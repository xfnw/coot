#include "wordlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]) {
	if (argc != 2) {
		printf("syntax\n");
		return 1;
	}

	size_t len = sizeof(words) / sizeof(&words);
	size_t i, k, s = 0;
	char *work[len], c, not = 0;
	int place = -1;

	while ('\0' != (c = argv[1][s++])) {
		switch (c) {
		case '!':
		case '/':
		case '-': not ^= 1; break;
		/* we map '1' to 0 and so on */
		case '1' ... '5': place = c - 49; break;
		case 'a' ... 'z':
			k = 0;

			if (place == -1) {
				for (i = 0; i < len; i++) {
					/* misuse xor for not's
					 * conditional negation */
					if ((strchr(words[i], c) != NULL) ^
					    not )
						work[k++] = words[i];
				}
			} else {
				for (i = 0; i < len; i++) {
					if ((c == words[i][place]) ^ not )
						work[k++] = words[i];
				}
			}

			place = -1;
			not = 0;
			len = k;
			memcpy(words, work, len * sizeof(&words));
			break;
		default: printf("unknown symbol %c\n", c); return 2;
		}
	}

	for (i = 0; i < len; i++) {
		printf("%s\n", words[i]);
	}
	printf("%zu word%s\n", len, "s" + (len == 1));
	return 0;
}
