/* Write a program to print all input lines that are longer than 80 characters. */

#include <stdio.h>
#define TEXTSIZE 1024
#define MINLINE 80

void printLines(char text[], int minlength);

int main() {
	char text[TEXTSIZE];
	int i, c;

	i = 0;
	while ((c = getchar()) != EOF && i < TEXTSIZE)
		text[i++] = c;
	text[i] = '\0';

	printf("\n");
	printLines(text, MINLINE);

	return 0;
}

void printLines(char text[], int minlen) {
	char line[TEXTSIZE];
	int t;	/* text index */
	int l;	/* line index */
	int c;

	t = l = 0;
	while ((c = text[t++]) != '\0') {
		if ((line[l++] = c) == '\n') {
			if (l > MINLINE) 
				printf("%s", line);
			l = 0;
		}
	}
}
