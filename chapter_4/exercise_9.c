/*
	Our getch and ungetch do not handle a pushed-back EOF correctly.
	Decide what their properties ought to be if an EOF is pushed back,
	then implement your design.
*/

main...
other stuff...

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
	else if (c == EOF)
		printf("ungetch: EOF cannot be pushed back");
	else
		buf[bufp++] = c;
}


