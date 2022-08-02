/*
	Write a version of itoa that accepts three arguments instead of two.
	The third argument is a minimum field width; the converted number must
	be padded with blanks on the left if necessary to make it wide enough.
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[], int minimum_width);
void reverse(char s[]);

int main() {
	char s[100];
	int n = 1234;
	
	printf("Input: %d\n", n);
	itoa(n, s, 6);
	printf("Output: %s\n", s);

	return 0;
}

void itoa(int n, char s[], int w) {
	int i, sign;
	unsigned int pn; // positive n
	pn = (sign=n)<0 ? -n : n;

	i = 0;
	do {
		s[i++] = pn % 10 + '0';
	} while ((pn /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';
	
	for (; i < w; i++)
		s[i] = ' ';

	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]) {
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}


