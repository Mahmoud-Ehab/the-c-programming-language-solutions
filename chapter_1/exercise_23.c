/* Write a program to remove all comments for a C program. Don't forget to handle quoted
 * strings and character constants properly. C comments do not nest. */

#include <stdio.h>

#define CODESIZE 1024
#define SCAN_NORMAL 0
#define SCAN_IN_QUOTES 1
#define SCAN_IN_COMMENT_TYPE1 2
#define SCAN_IN_COMMENT_TYPE2 3

void display();
void getinput();
void rmvcomments();
int isincomment(int index);
int isinquotes(int index);

int scanstatus = SCAN_NORMAL;
char code[CODESIZE];

int main() {
	getinput();
	rmvcomments();
	display();
	return 0;
}


void display() {
	int c;
	int i = 0;

	while ((c = code[i++]) != EOF)
		putchar(c);
}


void getinput() {
	int c;
	int i = 0;

	for (; i < CODESIZE-1 && (c = getchar()) != EOF;) 
		code[i++] = c;

	code[i] = EOF;
}


void rmvcomments() {
	int i = 0;

	while (code[i] != EOF) {
		if (isincomment(i))
			code[i] = '\0';
		i++;
	}
}


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
