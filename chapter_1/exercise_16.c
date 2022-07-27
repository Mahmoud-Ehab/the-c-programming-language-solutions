/* Revise the main routine of the longest-line program so it will correctly 
 * print the length of arbitrarily long input lines, and as much as possible 
 * of the text. */

#include <stdio.h>

int getLineLength();
void copy(char to[], char from[]);

int main() {
	int len;		/* current line length */
	int max;		/* maximum length seen so far */

	max = 0;
	while ((len = getLineLength()) != 0)
		if (len > max)
			max = len;

	printf("Longest Line Length: %d\n", max);
	return 0;
}

int getLineLength() {
	int l, c;

	l = 0;
	while ((c = getchar()) != EOF && c != '\n')
		l++;

	return l;
}
