/*
	Write a routine ungets(s) that will push back an entire string
	onto the input. Should ungets know about buf and bufp, or should 
	it just use ungetch?
*/

main...
other stuff...

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

/* push an entire string back on input */
void ungets(char s[]) {
	int c, i=0;
	while ((c = s[i++]) != '\0')
		ungetch(c);
}


