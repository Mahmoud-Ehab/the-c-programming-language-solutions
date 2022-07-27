/* Write a program to count blanks, tabs, and newlines. */

#include <stdio.h>

int main() {
	long numOfNewlines = 0;
	long numOfBlanks = 0;
	long numOfTabs = 0;
	int c;

	printf("Input a string\n");
	printf("CTRL + D for end-of-file\n");
		
	while ((c = getchar()) != EOF) {
		if (c == '\n') numOfNewlines++;
		else if (c == ' ') numOfBlanks++;
		else if (c == '\t') numOfTabs++;
	}
	
	printf("\n");
	printf("newlines: %ld\n", numOfNewlines);
	printf("blanks: %ld\n", numOfBlanks);
	printf("tabs: %ld\n", numOfTabs);
}
