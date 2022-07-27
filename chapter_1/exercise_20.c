/* Write a program 'detab' that replaces tabs in the input with the proper number
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops, say 
 * every n columns. Should n be a variable or a symbolic parameter? */

#include <stdio.h>

void detab(int tabstop);

int main() {
	int tabsize = 4;
	int c;
	
	printf("(CTRL + D for EOF)\n");

	while ((c = getchar()) != EOF) {
		if (c == '\t') detab(tabsize);
		else putchar(c);
	}

	return 0;
}

void detab(int tabstop) {
	for (int i = 0; i < tabstop; i++)
		putchar(' ');
}
