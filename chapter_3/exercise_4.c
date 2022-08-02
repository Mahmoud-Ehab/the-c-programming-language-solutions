/*
	In a two's complement number representation, our version of "itoa" does 
	not handle the largest negative number, that is, the value of n equal to 
	-(2^(wordsize-1)). Explain why not. Modify it to print that value corre-
	ctly, regardless of the machine on which it runs. (page 64)
*/

/*
	Because in two's complement number representation, the bigest negative
	value that can be represented always exceeds the positive by one. So that, 
	the statement "n = -n;" in itoa function doesn't work as expected.
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
	char s[100];
	int n = INT_MIN;
	
	printf("Input: %d\n", n);
	itoa(n, s);
	printf("Output: %s\n", s);

	return 0;
}

void itoa(int n, char s[]) {
	int i, sign;
	unsigned int pn; // positive n
	pn = (sign=n)<0 ? -n : n;

	i = 0;
	do {
		s[i++] = pn % 10 + '0';
	} while ((pn /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]) {
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}


