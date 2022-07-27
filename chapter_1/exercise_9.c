/* Write a program to copy its input to its output, replacing 
 * each string of one or more blanks with a single blank. */

#include <stdio.h>

int main() {
	printf("Write a string:\n");
	printf("(Press CTRL + D for EOF)\n");

	int c;
	int blankFound = 0;
	while ((c = getchar()) != EOF) {
		if (!blankFound) putchar(c);

		if (c == ' ') blankFound = 1;
		else blankFound = 0;
	}
}
