/* Rewrite the temprature conversion program of Section 1.2 to use a function for conversion. */

#include <stdio.h>

#define LOWER 0
#define UPPER 100
#define STEP 10

float fahrFromCels(int cels);

int main() {
	printf("cels \t fahr\n");

	for (int cels = LOWER; cels <= UPPER; cels += STEP) {
		float fahr = fahrFromCels(cels);
		printf("%d\t%.1f\n", cels, fahr);
	}
}

float fahrFromCels(int cels) {
	return (9.0 * cels / 5.0) + 32;
}
