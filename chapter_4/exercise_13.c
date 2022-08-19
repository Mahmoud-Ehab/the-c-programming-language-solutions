/*
	Write a recursive version of the function reverse(s), which
	reverses the string s in place.
*/

#include <stdio.h>
#include <string.h>

void reverse(char s[], int i, int j);

int main() {
	char s[] = "Hello world";
	printf("normal: %s\n", s);
	reverse(s, 0, strlen(s)-1);
	printf("reversed: %s\n", s);
	return 0;
}

void reverse(char s[], int i, int j) {
	char temp = s[i];
	s[i] = s[j];
	s[j] = temp;

	if(i < j)
		reverse(s, i+1, j-1);
}
