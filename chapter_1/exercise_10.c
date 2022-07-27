/* Write a program to copy its input to its output, replacing each 
 * tab by \t, each backspace by \b, and each backslash by \\. 
 * This makes tabs and backspaces visible in an umambiguous way. */

#include <stdio.h>

int main() {
	printf("Write a string:\n");
	printf("(Press CTRL + D for EOF)\n");

	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\t') { 
			putchar('\\');
			putchar('t');
		}
		else if (c == '\b') {	
			putchar('\\');
			putchar('b');
		}
		else if (c == '\\') {
			putchar('\\');
			putchar('\\');
		}
		else putchar(c);
	}
}
