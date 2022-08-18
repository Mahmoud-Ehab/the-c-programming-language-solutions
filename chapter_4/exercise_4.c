/*
	Add commands to print the top element of the stack without poping,
	to duplicate it, and to swap the top two elements. Add a command to
	clear the stack.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
void showtop(void);
void duptop(void);
void swaptop2(void);
void clear(void);

/* reverse Polish calculator */
int main() {
	int type;
	double op2;
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
				double op1 = pop();
				if (op1 >= 0.0 && op2 >= 0.0)
					push((int)op1 % (int)op2);
				else
					printf("error: negative values entered for mod calculation");
				break;
			case '?':
				showtop();
				break;
			case 'd':
				duptop();
				break;
			case 's': 
				swaptop2();
				break;
			case 'c':
				clear();
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

/* gettop: print the top value and return it */
void showtop(void) {
	double top = val[sp-1];
	printf("%0.8g\n", top);
}

/* duptop: duplicate the top value */
void duptop(void) {
	double top = val[sp-1];
	push(top);
}

/* swaptop2: swap the top two values */
void swaptop2(void) {
	double tmp = val[sp-1];
	val[sp-1] = val[sp-2];
	val[sp-2] = tmp;
}

/* clear: clear the stack; remove all elements */
void clear(void) {
	sp = 0;
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


