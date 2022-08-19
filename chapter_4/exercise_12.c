/*
	Adapt the ideas of printd to write a recursive version of itoa; that is,
	convert an integer into a string by calling a recursive routine.
*/

#include <stdio.h>

int itoa(int num, char s[], int i);

int main() {
	char s[45];
	itoa(51245, s, 0);
	printf("%s\n", s);
	return 0;
}

int itoa(int num, char s[], int i) {
	if (num < 0) {
		s[i++] = '-';
		num = -num;
	}
	if (num / 10) {
		int r = itoa(num / 10, s, i);
		s[r] = num % 10 + '0';
		s[r+1] = '\0';
		return r+1;
	}
	else {
		s[i] = num % 10 + '0';
		s[i+1] = '\0';
		return i+1;
	}
}
