/*
	Suppose that there will never be more than one character of pushback.
	Modify getch and ungetch accordingly.
*/

main...
other stuff...

char buf = '\0';

/* get a (possibly pushed back) character */
int getch(void) {
	if (buf == '\0')
		return getchar();
	else
		char tmp = buf, buf = '\0', return tmp;
}

/* push character back on input */
void ungetch(int c) {
	if (buf == '\0')
		buf = c;
	else
		printf("error: ungetch: there is already a char stored in buf.");
}


