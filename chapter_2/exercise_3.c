/*
	Write the function htoi(s), which converts a string of hexadecimal digits
	(including an optional 0x or 0X) into its equivalent integer value. The
	allowable digits are 0 through 9, a through f, and A through F.
*/

#include <stdio.h>


int htoi(char string[]);
int todigit(char c);

int main() {
	int c;
	do {
		int i = 0;
		char input[10];
	
		printf("Write a hexadecimal: ");
		while ((c = getchar()) != '\n' && c != EOF)
			input[i++] = c;
		input[i] = '\0';
		printf("integer: %d\n", htoi(input));
	 } while (c != EOF);

	return 0;
}


// It's assumed that hexa contains a valid hexadecimal digits (0x or 0X are optional)
int htoi(char hexa[]) {
	int returnValue = 0;

	// investigate the end of hexa
	int end = 0;
	while (hexa[end] != '\0') end++;
	
	// loop over hexa starting from the end
	int pivot = end-1;
	for (int i = pivot; i >= 0 && hexa[i] != 'x' && hexa[i] != 'X'; i--) {
		int digit = todigit(hexa[i]); // convert char to digit. like: 'f' -> 15
		int pos = pivot - i;

		// for loop to evaluate 16 power pos
		int powValue = 1;
		for (int i = 0; i < pos; i++)
			powValue *= 16;

		returnValue += digit * powValue;
	}

	return returnValue;
}

int todigit(char c) {
	if (c >= '0' && c <= '9')
		return c - '0';
	else if (c >= 'a' && c <= 'f')
		return c - 'a' + 10;
	else if (c >= 'A' && c <= 'F')
		return c - 'A' + 10;
}


