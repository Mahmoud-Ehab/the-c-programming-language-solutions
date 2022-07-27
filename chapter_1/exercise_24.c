/* Write a program to check a C program for rudimentary syntax errors like
 * unbalanced parentheses, brackets and braces. Don't forget about quotes,
 * both single and double, escape sequences, and comments. (This program 
 * is hard if you do it in full generality) */

#include <stdio.h>

#define CODESIZE 1024
#define SCAN_STACK_SIZE 10

#define SCAN_NORMAL 0
#define SCAN_IN_QUOTES 1
#define SCAN_IN_COMMENT_TYPE1 2
#define SCAN_IN_COMMENT_TYPE2 3


void getinput();
int isincomment(int index);
int isinquotes(int index);
void scanstack_push(char c);
char scanstack_pop();

char code[CODESIZE];
int scanstatus = SCAN_NORMAL;
char scanstack[SCAN_STACK_SIZE];
int scanstack_len = 0;

int main() {
	// Get the input code from the user
	getinput();

	// Loop over the code string and check errors by using scanstack
	int i = -1;
	int c;
	
	while ((c = code[++i]) != EOF) {
		if (isincomment(i) || isinquotes(i)) continue;

		if (c == '(' || c == '{' || c == '[')
			scanstack_push(c);
		else if (c == ')' || c == '}' || c == ']') {
			char pv = scanstack[scanstack_len-1];

			if (c == ')' && pv != '(') break;
			else if (c == '}' && pv != '{') break;
			else if (c == ']' && pv != '[') break;
			
			scanstack_pop();
		}
	}
	
	// Print an error message if any exists
	if (scanstack_len > 0)
		printf("An error has been found in %d position.\n", i);

	return 0;
}


void getinput() {
	int c;
	int i = 0;

	for (; i < CODESIZE-1 && (c = getchar()) != EOF;) 
		code[i++] = c;

	code[i] = EOF;
}


void scanstack_push(char c) {
	scanstack[scanstack_len] = c;
	scanstack_len += 1;
}

char scanstack_pop() {
	char tmp = scanstack[scanstack_len-1];
	scanstack[scanstack_len-1] = 0;
	scanstack_len -= 1;
	return tmp;
}


/* A scan-status-relevant function, that checks if the i position from a global 
string variable is in comment or not, and updates the status accordingly. */
int isincomment(int i) {
	if (isinquotes(i))
		return 0;

	else if (scanstatus == SCAN_NORMAL) {
		if (code[i] == '/' && code[i+1] == '*')
			scanstatus = SCAN_IN_COMMENT_TYPE1;
		else if (code[i] == '/' && code[i+1] == '/')
			scanstatus = SCAN_IN_COMMENT_TYPE2;
	}

	else if (scanstatus == SCAN_IN_COMMENT_TYPE1) {
		if (code[i] == '*' && code[i+1] == '/') {
			code[i] = code[i+1] = '\0';
			scanstatus = SCAN_NORMAL;
		}
	}

	else if (scanstatus == SCAN_IN_COMMENT_TYPE2) {
		if (code[i] == '\n') 
			scanstatus = SCAN_NORMAL;
	}
	
	int cond1 = scanstatus == SCAN_IN_COMMENT_TYPE1;
	int cond2 = scanstatus == SCAN_IN_COMMENT_TYPE2;
	return cond1 || cond2; 
}


/* A scan-status-relevant function, that checks if the i position from a global 
string variable is in quotes or not, and updates the status accordingly. */
int isinquotes(int i) {
	if (scanstatus == SCAN_NORMAL) {
		if (code[i] == '"')
			scanstatus = SCAN_IN_QUOTES;
		else if (code[i] == '\'')
			scanstatus = SCAN_IN_QUOTES;	
	}

	else if (scanstatus == SCAN_IN_QUOTES) {
		if (code[i] == '"')
			scanstatus = SCAN_NORMAL;
		else if (code[i] == '\'')
			scanstatus = SCAN_NORMAL;	
	}

	return scanstatus == SCAN_IN_QUOTES;
}
