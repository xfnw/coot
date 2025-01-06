#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int main(void) {
	initscr();
	curs_set(0);
	nocbreak();
	addstr("waiting for stdin...");
	move(0, 0);
	refresh();

	char *line = NULL;
	size_t len = 0, row = 0;
	while (getline(&line, &len, stdin) != -1) {
		/* TODO: unicode support, irc formatting, line
		 * wrapping */
		addnstr(line, COLS);
		row = (row + 1) % LINES;
		mvhline(row, 0, '-', COLS);
		refresh();
	}

	free(line);
	endwin();
	return 0;
}
