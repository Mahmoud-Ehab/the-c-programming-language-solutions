/*
	Write the function any(s1,s2), which returns the first location in s1 where any
	character in s2 occurs, or -1 if s1 contains no characters from s2.
*/

#include <stdio.h>


int setstring(char s[]);
int any(char s1[], char s2[]);
int isin(char c, char s[]);

int main() {
	char str1[1024];
	char str2[1024];
	
	printf("Enter String 1: \n");
	setstring(str1);
	
	printf("\nEnter String 2: \n");
	setstring(str2);
	
	int p = any(str1, str2);
	if (p == -1)
		printf("\nDidn't find any mutual char between s1 and s2.\n");
	else
		printf("\nFound %c at index %d.\n", str1[p], p);

	return 0;
}

int setstring(char s[]) {
	int c;
	int i = 0;

	for (; (c=getchar()) != '\n';)
		s[i++] = c;
	s[i] = '\0';

	return i;
}

int any(char s1[], char s2[]) {
	int i = 0;

	for (i = 0; s1[i] != '\0'; i++)
		if (isin(s1[i], s2))
			return i;
	
	return -1;
}

int isin(char c, char s[]) {
	for (int i=0; s[i] != '\0'; i++)
		if (s[i] == c)
			return 1;

	return 0;
}


