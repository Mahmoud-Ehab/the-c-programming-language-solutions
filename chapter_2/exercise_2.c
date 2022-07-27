/*
	Write a loop equivalent to the for loop above (page 41) without using && or ||.
*/

#include <stdio.h>

#define MAX_LINE_LEN 45 

int getLine(char line[]);

int main() {
	char line[MAX_LINE_LEN];
	
	while (getLine(line) != 0) {
		for (int i=0; i < MAX_LINE_LEN && line[i] != '\0'; i++) {
			putchar(line[i]);
		}
		putchar('\n');
	}

	return 0;
}

int getLine(char line[]) {
	int c;
	int i = 0;

	while (i < MAX_LINE_LEN-1) {
		c = getchar();
		if (c == EOF) 
			break;
		else if (c == '\n')
			break;
		else
			line[i++] = c;
	}

	line[i] = '\0';
	return i;
}

