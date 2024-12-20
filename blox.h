/* SPDX-FileCopyrightText: 2024 xfnw
 * SPDX-License-Identifier: MIT
 *
 * teeny tiny unicode block character drawing library
 * named after a very nice feesh :3
 */

#include <stdbool.h>
#include <stdio.h>

const char *blox_disp_chars[] = {" ", "▀", "▄", "█"};

void blox_draw(const unsigned char *frame) {
	unsigned short fx, fy;
	for (fy = 0; fy < BLOX_RH; fy++) {
		for (fx = 0; fx < BLOX_RW; fx++) {
			unsigned char s, c;
			c = frame[BLOX_RW * fy + fx];
			for (s = 0; s < 4; s++) {
				fputs(blox_disp_chars[c & 3], stdout);
				c >>= 2;
			}
		}
		putc('\n', stdout);
	}
}

void blox_set(unsigned char *frame, unsigned short x, unsigned short y) {
	frame[BLOX_RW * (y >> 1) + x / 4] |= 1 << ((x % 4) * 2 + (y & 1));
}

void blox_del(unsigned char *frame, unsigned short x, unsigned short y) {
	frame[BLOX_RW * (y >> 1) + x / 4] &= ~(1 << ((x % 4) * 2 + (y & 1)));
}

bool blox_get(const unsigned char *frame, unsigned short x, unsigned short y) {
	return frame[BLOX_RW * (y >> 1) + x / 4] & 1 << ((x % 4) * 2 + (y & 1));
}
