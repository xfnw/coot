#include <stddef.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

char *ringtail_buf_create(size_t size) {
	if (size % getpagesize() != 0)
		return NULL;

	char *buf = mmap(NULL, size * 2, PROT_READ | PROT_WRITE,
			 MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if (buf == MAP_FAILED)
		return NULL;

	if (mremap(buf, size, size,
		   MREMAP_FIXED | MREMAP_MAYMOVE | MREMAP_DONTUNMAP,
		   buf + size) != buf + size)
		return NULL;

	return buf;
}

int ringtail_buf_free(char *buf, size_t size) {
	if (size % getpagesize() != 0)
		return -1;

	return munmap(buf, size * 2);
}

struct ringtail {
	char *buf;
	size_t size;
	size_t inp;
	size_t out;
};

void ringtail_init(struct ringtail *ring, ssize_t size) {
	ring->buf = ringtail_buf_create(size);
	ring->size = size;
	ring->inp = 0;
	ring->out = 0;
}

int ringtail_free(struct ringtail *ring) {
	return ringtail_buf_free(ring->buf, ring->size);
}

int ringtail_read(struct ringtail *ring, int fd) {
	ring->inp = ring->inp % ring->size;
	size_t space = (ring->size + ring->out - ring->inp) % ring->size;
	if (space == 0)
		space = ring->size;

	ssize_t added = read(fd, ring->buf + ring->inp, space - 1);

	if (added != -1)
		ring->inp += added;
	return added;
}

char *ringtail_getline(struct ringtail *ring) {
	ring->out = ring->out % ring->size;
	size_t space = (ring->size + ring->inp - ring->out) % ring->size;

	char *start = ring->buf + ring->out;
	char *newline = memchr(start, '\n', space);
	if (newline == NULL)
		return NULL;

	*newline = '\0';
	ring->out += newline - start + 1;
	return start;
}
