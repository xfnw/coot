#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define OPEN(n) \
	if (-1 == (file##n = open(argv[n], O_RDONLY))) \
		return errno;

#define READ(n) read(file##n, &buf##n, sizeof buf##n)

ssize_t min(ssize_t a, ssize_t b) { return a < b ? a : b; }

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("usage: %s file1 file2\n", *argv);
		return EINVAL;
	}

	int file1, file2;
	OPEN(1);
	OPEN(2);

	unsigned long long buf1, buf2;
	ssize_t minsize;
	do {
		minsize = min(READ(1), READ(2));
		buf1 ^= buf2;
		write(STDOUT_FILENO, &buf1, minsize);
	} while (minsize == sizeof buf1);
}
