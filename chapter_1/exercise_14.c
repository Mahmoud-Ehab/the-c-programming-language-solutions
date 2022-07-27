/* Write a program to print a histogram of the frequencies of different 
 * characters in its input. */

#include <stdio.h>

#define NUM_OF_LETTERS 26
#define PROGRESS_CHAR '|'

int main() {
	int hist[NUM_OF_LETTERS];
	int c, maxFreq;

	maxFreq = 0;
	for (int i = 0; i < NUM_OF_LETTERS; i++) 
		hist[i] = 0;

	printf("Input a string:\n");	
	printf("(press CTLR + D for EOF)\n");

	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z') {
			hist[c-'a']++;
		}
		else if (c >= 'A' && c <= 'Z') {
			hist[c-'A']++;
		}
	}
	
	// Determine the max number of frequencies
	for (int i = 0; i < NUM_OF_LETTERS; i++) 
		if (maxFreq < hist[i])
			maxFreq = hist[i];

	// Draw the histogram
	printf("\n");
	for (int f = 0; f <= maxFreq; f++) {
		for (int i = 0; i < NUM_OF_LETTERS; i++) {
			if (f == maxFreq)
				printf("  %c", 'a' + i);
			else if ((maxFreq - f) <= hist[i])
				printf("  %c", PROGRESS_CHAR);
			else
				printf("   ");
		}
		printf("\n");
	}

	return 0;
}
