#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>

unsigned short crc16_1021(unsigned short state, unsigned char *data,
			  ssize_t len) {
	while (len--) {
		unsigned char x;

		x = state >> 8 ^ *data++;
		x ^= x >> 4;
		state = (state << 8) ^ (x << 12) ^ (x << 5) ^ x;
	}

	return state & 0xFFFF;
}

int main(int argc, char *argv[]) {
	unsigned short state = 0x0000;
	unsigned char buf[8192];
	ssize_t len;

	while ((len = read(STDIN_FILENO, buf, sizeof(buf) - 1))) {
		state = crc16_1021(state, buf, len);
	}

	char outfmt = 'x';
	if (argc > 1)
		outfmt = *argv[1];

	switch (outfmt) {
	case 'b':
		state = htons(state);
		write(STDOUT_FILENO, &state, 2);
		break;
	case 'd': printf("%hd\n", (short)state); break;
	case 'D': printf("%hu\n", state); break;
	case 'x': printf("%04x\n", state); break;
	default:
		printf("b d %hd D %hu x %04x\n", (short)state, state, state);
		break;
	}
}
