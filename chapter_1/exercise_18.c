/* Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines. */

#include <stdio.h>
#define TEXTSIZE 1024

void trim(char origin[], char trimmed[]);

int main() {
	char text[TEXTSIZE];
	char trimmed[TEXTSIZE];
	int i, c;

	i = 0;
	while ((c = getchar()) != EOF && i < TEXTSIZE)
		text[i++] = c;
	text[i] = '\0';
	
	trim(text, trimmed);
	printf("\nAfter trimming:\n");
	printf("%s\n", trimmed);

	return 0;
}

void trim(char origin[], char trimmed[]) {
	int o; /* origin index */
	int t; /* trimmed index */
	int c;

	o = t = -1;
	while ((c = origin[++o]) != '\0') {
		if (c == ' ' && c == trimmed[t]) continue;
		else if (c == '\t' && c == trimmed[t]) continue;
		else if (c == '\n' && c == trimmed[t]) continue;
		else trimmed[++t] = c;
	}
	trimmed[++t] = '\0';
}
