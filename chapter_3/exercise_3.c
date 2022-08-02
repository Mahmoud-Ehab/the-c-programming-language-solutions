/*
	Write a function expand(s1,s2) that expands shorthand notations like a-z
	in the string s1 into the equivalent complete list abc...xyz in s2. Allow
	for letters of either case and digits, and be prepared to handle cases like
	a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taking 
	literally.
*/

#include <stdio.h>

#define A_Z 1
#define a_z 2
#define ZERO_9 3

char scanner[5];

void expand(char s1[], char s2[]);
void pushIntoScanner(char c);
int notationFound();

int main() {
	char s1[1024];
	char s2[1024];
	
	printf("Input (CTRL+D to end):\n");
	int c, i = 0;
	while ((c = getchar()) != EOF)
		s1[i++] = c;
	s1[i] = '\0';
	
	expand(s1, s2);
	printf("\n%s\n", s2);
	
	return 0;
}


void expand(char s1[], char s2[]) {
	int c;
	int i = 0, k = 0;
	
	for (int j = 0; j < 5; j++)
		scanner[j] = ' ';

	do {
		c = s1[i++];
		pushIntoScanner(c);
		if (notationFound()) {
			k -= 3; // remove the notation from s2
			for (int f = scanner[1]; f <= scanner[3]; f++)
				s2[k++] = f;
		}
		else
			s2[k++] = c;
	}
	while(c != '\0');
	s2[k] = '\0';
}


void pushIntoScanner(char c) {
	for (int i = 0; i < 5; i++) {
		if (i == 4)
			scanner[i] = c;
		else
			scanner[i] = scanner[i+1];
	}
}


int notationFound() {
	if (scanner[0] != ' ') return 0;
	else if (scanner[2] != '-') return 0;
	else if (
		scanner[4] != ' ' && 
		scanner[4] != '\n' && 
		scanner[4] != '\0'
	) return 0;

	if (scanner[1] >= '0' && scanner[1] <= '9')
		if (scanner[3] >= '0' && scanner[3] <= '9')
			return ZERO_9;
	
	if (scanner[1] >= 'a' && scanner[1] <= 'z')
		if (scanner[3] >= 'a' && scanner[3] <= 'z')
			return a_z;

	if (scanner[1] >= 'A' && scanner[1] <= 'Z')
		if (scanner[3] >= 'A' && scanner[3] <= 'Z')
			return A_Z;
	
	return 0;
}


