#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define stok(varname, ptr, delim) \
	varname = strtok(ptr, delim); \
	if (varname == NULL) \
	return

void doline(char *line) {
	const char *name, *cmd;
	const char *newname = "";

	stok(name, line, " :\n");

	do {
		stok(cmd, NULL, " \n");
	} while (*cmd >> 5 != 2); /* go until capital letter */

	if (!strcmp("KILL", cmd)) {
		/* use name from KILL parameter */
		stok(name, NULL, " :\n");
	} else if (!strcmp("NICK", cmd)) {
		stok(newname, NULL, " :\n");
	}

	printf("%s %s %s\n", cmd, name, newname);
}

int main(void) {
	char *linebuf = malloc(1024);
	size_t linesize = 1024;

	while (getline(&linebuf, &linesize, stdin) != -1) {
		char *line = linebuf;
		doline(line);
	}

	free(linebuf);
}
