/* Write a function reverse(s) that reverses the character string s. Use it 
 * to write a program that reverses its input a line at a time. */

#include <stdio.h>
#define LINESIZE 1024

int getLine(char line[]);
int getStringLen(char string[]);
void reverse(char string[]);

int main() {
	char line[LINESIZE];

	while (getLine(line) != 0) {
		reverse(line);
		printf("%s\n", line);
	}
	return 0;
}

int getLine(char line[]) {
	int i, c;
	for (i = 0; i < LINESIZE-1 && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;
	line[i] = '\0';
	return i;
}

int getStringLen(char str[]) {
	int l = 0;
	while (str[l] != '\0') l++;
	return l;
}

void reverse(char str[]) {
	int length = getStringLen(str);

	for (int i = 0; i < length/2; i++) {
		char tmp = str[i];
		str[i] = str[length-i-1];
		str[length-i-1] = tmp;
	}
}
