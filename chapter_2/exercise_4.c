/*
	Write an alternate version of squeeze(s1, s2) that deletes each character in s1
	that matches any character in s2.
*/

#include <stdio.h>


int setstring(char s[]);
int squeeze(char s1[], char s2[]);
int isin(char c, char s[]);

int main() {
	char str1[1024];
	char str2[1024];
	
	printf("Enter String 1: \n");
	setstring(str1);
	
	printf("\nEnter String 2: \n");
	setstring(str2);

	printf("\nAfter removing s2 from s1: \n");
	squeeze(str1, str2);
	printf("%s\n", str1);

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

int squeeze(char s1[], char s2[]) {
	int i, j;

	for (i = j = 0; s1[i] != '\0'; i++)
		if (!isin(s1[i], s2))
			s1[j++] = s1[i];
	s1[j++] = s1[i];
}

int isin(char c, char s[]) {
	for (int i=0; s[i] != '\0'; i++)
		if (s[i] == c)
			return 1;

	return 0;
}


