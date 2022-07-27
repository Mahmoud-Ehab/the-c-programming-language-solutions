/*
	Rewrite the function lower, which converts upper case letter to lower case,
	with the conditional expression instead of if-else.
*/

#include <stdio.h>

int lower(char);

int main() {
	int c;
	while ((c = getchar()) != EOF)
		putchar(lower(c));
	return 0;
}

int lower(char c) {
	int isUpperLetter = (c >= 'A') && (c <= 'Z');
	return isUpperLetter ? (c + 'a' - 'A') : c;
}  
