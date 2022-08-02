/*
	Write a function escape(s,t) that converts characters like newline and tap
	into visible escape sequences like \n and \t as it copies the string t to s.
	Use a switch. Write a function for the other direction as well, coverting 
	escape sequences into the real characters.
*/

#include <stdio.h>

#define INPUT_MAX_LEN 1024

void getUserInput(char input[], int len);
void escape(char s[], char t[]);
void real(char s[], char t[]);

int main() {
	char input[INPUT_MAX_LEN];
	printf("Input (CTRL+D to escape): \n");
	getUserInput(input, INPUT_MAX_LEN);

	char output[INPUT_MAX_LEN];
	printf("\nDisplaying \\n and \\t:\n");
	escape(output, input);
	printf("%s\n", output);

	char output2[INPUT_MAX_LEN];
	printf("\nDisplaying it again in the right form:\n");
	real(output2, output);
	printf("%s\n", output2);

	return 0;
}


void getUserInput(char input[], int len) {
	int c;
	int i = 0;

	for (; (c = getchar()) != EOF && i < len; i++)
		input[i] = c;
	
	input[i] = '\0';
}


void escape(char s[], char t[]) {
	int i = 0, k = 0;
	int c;

	while ((c = t[k++]) != '\0') {
		switch(c) {
			case '\n':
				s[i++] = '\\';
				s[i++] = 'n';
				break;
			case '\t':
				s[i++] = '\\';
				s[i++] = 't';
				break;
			default:
				s[i++] = c;
				break;
		}
	}
	s[i] = '\0';
}


void real(char s[], char t[]) {
	int i = 0, k = 0;
	int c;

	while ((c = t[k++]) != '\0') {
		switch(c) {
			case '\\':
				if (t[k] == 'n' || t[k] == 't') {
					s[i++] = t[k]=='t' ? '\t' : '\n';
					k++;
					break;
				}
			default:
				s[i++] = c;
		}
	}
	s[i] = '\0';
}


