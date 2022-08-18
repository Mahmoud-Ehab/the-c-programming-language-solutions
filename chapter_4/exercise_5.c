/*
	Add access to library functions like sin, exp, and pow.
	See <math.h> in Appendix B, Section 4.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main() {
	int type;
	double op1 = 0.0, op2 = 0.0;
	char s[MAXOP];
	
	while ((type = getop(s)) != EOF) {
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
				op1 = pop();
				if (op1 >= 0.0 && op2 >= 0.0)
					push((int)op1 % (int)op2);
				else
					printf("error: negative values entered for mod calculation");
				break;
			// sin command
			case 's':
				op2 = pop();
				push(sin(op2));
				break;
			// exp command
			case 'e':
				op2 = pop();
				push(exp(op2));
				break;
			// pow command
			case 'p':
				op2 = pop();
				op1 = pop();
				push(pow(op1, op2));
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

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]) {
	int i, c;
	
	// Skip spaces and tabs
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	
	// If it's an operator (not a digit) return it
	if (!isdigit(c) && c != '.')
		return c;
	
	// Otherwise, if it's (the input char) a digit
	i = 0;
	if (isdigit(c)) // integer part
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') // fraction part
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	
	// push any character back in input
	// (so when getch() get called after, c can be read again)
	if (c != EOF)
		ungetch(c);
	
	return NUMBER;
}


#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

/* get a (possibly pushed back) character */
int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}


