/* Write a program to 'fold' long input lines into two or more shorter lines 
 * after the last non-blank character that occurs before the n-th column 
 * of input. Make sure your program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column. */



#include <stdio.h>

int getLine(char line[]);
void fold(char line[], int maxlen);
int isLetter(char c);

int maxLineLen = 1024;

int main() {
	char line[maxLineLen];
	int foldLen = 60;
	
	printf("(CTRL + D for EOF)\n");

	while (getLine(line) != 0) {
		fold(line, foldLen);
		putchar('\n'); /* leave a space for the next input */
	}

	return 0;
}

int getLine(char line[]) {
	int c;
	int i = 0;
	for (; i < maxLineLen && (c = getchar()) != EOF && c != '\n';)
		line[i++] = c;	

	line[i] = '\0';
	return i; /* return the length of the input */
}

void fold(char line[], int maxlen) {
	int c;
	int i = 0;
	int boundary = maxlen;

	while ((c = line[i++]) != '\0') {
		if (boundary-i < maxlen-1 || isLetter(c))
			putchar(c);

		if (i >= boundary) {
			if (isLetter(c) && isLetter(line[i])) 
				putchar('-');
			putchar('\n');
			boundary += maxlen;
		}
	}
}

int isLetter(char c) {
	return (c != ' ' && c != '\t');
}
