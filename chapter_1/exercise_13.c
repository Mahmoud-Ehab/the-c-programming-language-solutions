/* Write a program to print a histogram of the lengths of words in its input.
 * Its easy to draw the histogram with the bars horizontal; a vertical orientation
 * is more challenging. */

#include <stdio.h>

#define MIN_WORD_LENGTH 1
#define PROGRESS_CHAR '|'

int main() {
	int curWordLength = 0;
	int maxWordLength = 0;
	int hist[100];
	int c;

	for (int i = 0; i < 100; i++) 
		hist[i] = 0;
	
	printf("Input a string:\n");
	printf("(press CTRL + D for EOF)\n");

	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z') 
			curWordLength++;
		else if (c >= 'A' && c <= 'Z') 
			curWordLength++;
		else if (c == '\'')
			curWordLength++;
		else if (curWordLength >= MIN_WORD_LENGTH) {
			hist[curWordLength]++;
			curWordLength = 0;
		}

		if (curWordLength > maxWordLength)
			maxWordLength = curWordLength;
	}

	// Determine the max element in hist array
	int maxLevel = 0;
	for (int i = MIN_WORD_LENGTH; i <= maxWordLength; i++) {
		if (hist[i] > maxLevel) maxLevel = hist[i];
	}

	// Draw the histogram
	printf("\n");
	for (int cl = 0; cl <= maxLevel; cl++) {
		for (int i = MIN_WORD_LENGTH; i <= maxWordLength; i++) {
			if (cl == maxLevel)
				printf("%3d", i);
			else if ((maxLevel - cl) <= hist[i])
				printf("  %c", PROGRESS_CHAR);
			else
				printf("   ");
		}
		printf("\n");
	}
}
