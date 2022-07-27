/*
	Write a program to determine the ranges of char, short, int, and long variables,
	both signed and unsigned, printing appropriate values from standard headers and
	by direct computation. Harder if you compute them: determine the ranges of the
	various floating point types.
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

#define TYPES_NUM 4 // no distinction between signed and unsigned


void computeRange(long range[2], int bits, int issigned);

char types[][10] = {
	"char", 
	"short", 
	"int", 
	"long", 
	"s_char", 
	"s_short", 
	"s_int", 
	"s_long"
};

long ranges[][2] = {
	{0, UCHAR_MAX}, 
	{0, USHRT_MAX}, 
	{0, UINT_MAX}, 
	{0, ULONG_MAX}
};

signed long sranges[][2] = {
	{SCHAR_MIN, SCHAR_MAX}, 
	{SHRT_MIN, SHRT_MAX}, 
	{INT_MIN, INT_MAX}, 
	{LONG_MIN, LONG_MAX}
};

// bit-size of each type, with respect to the types variable arragement
int sizes[] = {
	CHAR_BIT,
	16,
	32,
	64
};


int main() {
	printf("Determining the ranges by using standard headers...\n");
	for (int i = 0; i < TYPES_NUM; i++) {
		printf("The range of %s: ", types[i]);
		printf("%lu %lu\n", ranges[i][0], ranges[i][1]);

		printf("The range of %s: ", types[i+TYPES_NUM]);
		printf("%li %li\n", sranges[i][0], sranges[i][1]);
	}
	
	printf("\n---------\n");

	printf("Computing the ranges by using each type bit-size...\n");
	for (int i = 0; i < TYPES_NUM; i++) {
		long urange[2]; computeRange(urange, sizes[i], 0);
		long srange[2]; computeRange(srange, sizes[i], 1);

		printf("Unsigned %s: ", types[i]);
		printf("%lu %lu\n", urange[0], urange[1]);

		printf("Signed %s: ", types[i]);
		printf("-%lu %lu\n", srange[0], srange[1]);
	}
	
	return 0;
}


void computeRange(long range[2], int bits, int issigned) {
	if (issigned)
		bits -= 1;
	
	range[0] = 0;
	range[1] = 0;

	for (int i = 0; i < bits; i++) {
		long value = 1;
		for (int k = 0; k < i; k++)
			value *= 2;
		range[1] += value;
	}

	range[0] = issigned ? range[1]+1 : 0;
}


