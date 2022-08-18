/*
	Write the function strrindex(s,t), which returns the position of the 
	rightmost occurrence of t in s, or -1 if there is none.
*/

#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]);

int main() {
	char s[] = "Some random text to test the function";
	char t[] = "te";

	printf("input: %s\n", s);
	printf("search term: %s\n", t);

	printf("index: %d\n", strrindex(s,t));
	return 0;
}

/* strrindex: return index of the rightmost t in s, -1 if none */
int strrindex(char s[], char t[]) {
	int i, j, k;
	
	int slen = strlen(s)-1;
	int tlen = strlen(t)-1;

	for (i = slen; i >= 0; i--) {
		for (j=i, k=tlen; k >= 0 && t[k] == s[j]; j--, k--)
			;
		if (k < 0)
			return j+1;
	}
	return -1;
}


