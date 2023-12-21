#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[]) {
	if (argc != 2)
		return 1;

	const char *p = argv[1];
	int len = strlen(p);
	int o = len & 1;
	int t = 0;

	for (int i = 0; i < len; i++) {
		int s = (p[i] - '0') << (i & 1 ^ o);
		t += s / 10 + (s % 10);
	}

	printf("%d\n", (10 - t % 10) % 10);
}
