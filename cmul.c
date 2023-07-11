#include <stdio.h>
#include <stdlib.h>

long greatest_common_divisor(long x, long y) {
	long z;

	while (y) {
		z = x % y;

		x = y;
		y = z;
	}

	return x;
}

long least_common_multiple(long x, long y) {
	return x / greatest_common_divisor(x, y) * y;
}

int main(int argc, char *argv[]) {
	if (argc != 4) {
		printf("usage: %s operation x y\n", *argv);
		return 1;
	}

	long x = atol(argv[2]);
	long y = atol(argv[3]);

	switch (*argv[1]) {
	case 'g': printf("%ld\n", greatest_common_divisor(x, y)); break;
	case 'l': printf("%ld\n", least_common_multiple(x, y)); break;
	default: printf("operations may be g[cd] or l[cm]\n");
	}
}
