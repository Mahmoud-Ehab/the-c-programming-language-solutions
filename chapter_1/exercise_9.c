/* Write a program to copy its input to its output, replacing 
 * each string of one or more blanks with a single blank. */

#include <stdio.h>

int main() {
	printf("Write a string:\n");
	printf("(Press CTRL + D for EOF)\n");

	int c;
	int blankFound = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') 
			blankFound = 1;
		else if (blankFound) {
			blankFound = 0;
			putchar(' ');
		}

		if (!blankFound) 
			putchar(c);
	}
}
