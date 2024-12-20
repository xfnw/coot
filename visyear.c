/* SPDX-FileCopyrightText: 2024 xfnw
 * SPDX-License-Identifier: MIT
 *
 * visualize a year in the style of github's contribution charts
 *
 * takes ISO 8601-like dates at the start of stdin lines and shows
 * the previous year. everything after the first space is ignored.
 */

#define _GNU_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define W 56
#define H 8

#define BLOX_RW W / 4
#define BLOX_RH H / 2

#include "blox.h"

int main(void) {
	unsigned char frame[BLOX_RW * BLOX_RH] = {0};
	time_t now = time(NULL);
	struct tm *t = localtime(&now);
	int days = 364 + t->tm_wday;

	char *line = NULL;
	size_t size;

	while (-1 != getline(&line, &size, stdin)) {
		char *fst = strtok(line, " T\r\n");

		memset(t, 0, sizeof(*t));
		strptime(fst, "%Y-%m-%d", t);
		int ago = (int)((now - mktime(t)) / 86400);

		if (ago >= 365 || ago < 0)
			continue;

		blox_set(frame, (days - ago) / 7, (days - ago) % 7);
	}

	free(line);
	blox_draw(frame);
}
