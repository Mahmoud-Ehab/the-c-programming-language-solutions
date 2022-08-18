/*
	An alternate organization uses getline to read an entire input
	line; this makes getch and ungetch unnecessary. Revise the ca-
	lculator to use this approuch.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main() {
	int type;
	double op2;
	char s[MAXOP];
	
	while ((type = getop(s)) != '\0') {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				double op1 = pop();
				if (op1 >= 0.0 && op2 >= 0.0)
					push((int)op1 % (int)op2);
				else
					printf("error: negative values entered for mod calculation");
				break;
			case '\n':
				printf("result: %.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}



#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}



#include <ctype.h>

int getLine(void);

char line[100];
int li = -1; /* line index */

/* getop: get next operator or numeric operand */
int getop(char s[]) {
	int i, c;
	
	if (li == -1 || line[li] == '\0')
		getLine();

	// Skip spaces and tabs
	while ((s[0] = c = line[++li]) == ' ' || c == '\t')
		;
	s[1] = '\0';
	
	// If it's an operator (not a digit) return it
	if (!isdigit(c) && c != '.')
		return c;
	
	// Otherwise, if it's (the input char) a digit
	i = 0;
	if (isdigit(c)) // integer part
		while (isdigit(s[++i] = c = line[++li]))
			;
	if (c == '.') // fraction part
		while (isdigit(s[++i] = c = line[++li]))
			;
	s[i] = '\0';
	
	// push any character back in input
	// (so when getch() get called after, c can be read again)
	if (c != EOF)
		li--;

	return NUMBER;
}

int getLine(void) {
	int c, i = 0;
	while ((c = getchar()) != EOF)
		line[i++] = c;
	line[i] = '\0';
	return 0;
}

