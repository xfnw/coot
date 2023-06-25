#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LINELEN 512

#define stok(varname, ptr, delim)                                              \
	varname = strtok(ptr, delim);                                          \
	if (varname == NULL)                                                   \
	return

void json_escape_print(char *input) {
	char out[LINELEN*2] = "";
	char *outslice = out-1;
	char *inslice = input-1;
	unsigned char colormode = 255;

	while ((++outslice < out + LINELEN*2) && *(++inslice)) {
		if (*inslice < 0x1F) {
			colormode = 0;
			outslice--; /* drop character */
			continue;
		}
		/* FIXME: broken variable length color behavior
		 * ^C1,234567 should be 567 not 7 */
		if (colormode < 7) {
			if (*inslice == ',' || (*inslice >= '0' && *inslice <= '9')) {
				colormode++;
				outslice--; /* drop character */
				continue;
			} else {
				colormode = 255;
			}
		}
		if (*inslice == '\\' || *inslice == '"')
			*(outslice++) = '\\';

		*outslice = *inslice;
	}

	fputs(out, stdout);
}

void doline(char *line) {
	char *name, *cmd, *channel, *countstr, *topic;
	char *newname = "";
	int count;

	stok(name, line, ":\n");

	/* discard timestamp field */
	if (strtok(NULL, " \n") == NULL)
		return;
	stok(cmd, NULL, " \n");

	/* ignore non list replies */
	if (strcmp("322", cmd))
		return;

	/* discard nickname field */
	if (strtok(NULL, " \n") == NULL)
		return;

	stok(channel, NULL, " \n");
	stok(countstr, NULL, ":\n");

	count = atoi(countstr);
	if (count < 3)
		return;

	stok(topic, NULL, "\n");

	printf("{\"count\":%010d,\"channel\":\"", count);
	json_escape_print(channel);
	fputs("\",\"topic\":\"", stdout);
	json_escape_print(topic);
	fputs("\"}\n", stdout);
}

int main() {
	char *linebuf = malloc(1024);
	ssize_t linesize = 1024;

	while (getline(&linebuf, &linesize, stdin) != -1) {
		char *line = linebuf;
		doline(line);
	}

	free(linebuf);
}
