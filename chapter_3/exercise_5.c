/*
	Write the function itob(n,s,b) that converts the integer n into
	a base b character representation in the string s. In particular,
	itob(n, s, 16) formats n as a hexadecimal integer in s.
*/

#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
	char s[100];
	int n = 1003425;
	int b = 16;
	
	printf("number: %d\n", n);
	printf("to base: %d\n", b);
	itob(n, s, b);
	printf("output: %s\n", s);

	return 0;
}

void itob(int n, char s[], int b) {
	int m, i = 0;

	do {
		m = n % b;
		if (m <= 9)
			s[i++] = '0' + m;
		else
			s[i++] = 'a' + m - 10;
	} while ((n /= b) > 0);
	
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]) {
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}


