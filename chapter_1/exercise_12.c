/* Wrtie a program that prints its input one word per line. */

#include <stdio.h>

#define IN 0 /* inside a word */
#define OUT 1 /* NOT inside a word */

int IsEscapeCharacter(int c) {
	return (c == ' ' || c == '\n' || c == '\t');
}

int main() {
	int c;
	int state = OUT;

	printf("Input a string:\n");
	printf("(Press CTRL + D for EOF)\n");

	while ((c = getchar()) != EOF) {
		if (IsEscapeCharacter(c)) {
			if (state == IN) putchar('\n');
			state = OUT;
		}
		else {
			putchar(c);
			state = IN;
		}
	}
}

