/*
	In a two's complement number system, x &= (x-1) deletes the rightmost
	1-bit in x. Explain why. Use this observation to write a faster version
	of bitcount (page 50).
*/

/* 
	Loosely speaking, in binary number representation; when any number is augmented by one,
	technically, the number "1" is added to the rightmost bit and every bit changes corre-
	sponding to the following procedures, starting with the rightmost bit:

	1) if the bit value is 0, change it to 1,
	2) in case its value is already 1, return it to 0, 
		then add 1 to its left adjacent bit.
	
	Consequently, reducing x by one shall correspond to the following procedures, starting
	with the rightmost 1-bit (which is not always the rightmost bit):

	1) change the bit value from 1 to 0.
	2) change all adjacent right values to 1.

	Example: 
		0011011 + 1 = 0011100
		0011100 - 1 = 0011011

		let x = 0011100

		if y = x & (x-1)
		then y = 0011000

		if z = y & (y-1)
		then z = 0010000
*/


#include <stdio.h>

int bitcount(unsigned);

int main() {
	printf("%d\n", bitcount(25)); // 25 -> 11001
	return 0;
}

/* counts 1 bits in x */
int bitcount(unsigned x) {
	int b = 0;
	while (x != 0) {
		x &= (x-1);
		b++;
	}
	return b;
}


