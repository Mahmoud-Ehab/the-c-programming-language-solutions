/*
	Extend atof to handle scientific notation of the form 
		123.45e-6
	where a floating-point number may be followed by e or E and an 
	optionally signed exponent.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

double atof(char s[]);
void substr(char s1[], int from, int to, char s2[]);
int atoi(char s[]);

int main() {
	char s[] = "123.45e-6";
	printf("input: %s\n", s);
	printf("output: %lf\n", atof(s));
}

/* convert string s to double, with handling scientific notations */
double atof(char s[]) {
	double val, power;
	int i, sign;
	
	// skip white space
	for (i = 0; isspace(s[i]); i++)
		; 
	
	// Handle minus and plus sign
	if (isdigit(s[i]))
		sign = 1;
	else
		sign = (s[i++] == '-') ? -1 : 1;

	// Handle the decimal part
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	
	// Handle the dot (.)
	if (s[i] == '.')
		i++;

	// Handle the fractional part
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	// Handle scientific notation
	if (s[i] == 'e') {
		char sub[10]; 
		substr(s, ++i, strlen(s), sub);
		
		int n = atoi(sub);
		if (n < 0)
			for (int i=0; i < -n; i++)
				power *= 10.0;
		else
			for (int i=0; i < n; i++)
				power /= 10.0;
	}

	return sign * val / power;
}


void substr(char s1[], int from, int to, char s2[]) {
	int i, k;
	for (k=0, i=from; i < to; i++, k++)
		s2[k] = s1[i];
	s2[k] = '\0';
}


int atoi(char s[]) {
	return (int) atof(s);
}
