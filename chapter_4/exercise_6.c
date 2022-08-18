/*
	Add commands for handling variables. (It's easy to provide twenty-six
	variables with single-letter name.) Add a variable for the most rece-
	ntly printed value.
*/

/* 
	I'm not sure what they mean by handling variables; what shall one do
	with variables in a simple calculator. However, I'm gonna implement
	"ans" variable which stores the most recently printed value which could
	be accessed with the command 'a'. I think this seems reasonable enough.
*/
   
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

double ans = 0.0;

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
			case 'a':
				push(ans);
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
				ans = pop();
				printf("result: %.8g\n", ans);
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

