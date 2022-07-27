#include <stdio.h>

#define LOWER 0
#define UPPER 100 
#define STEP 10

int main() {
	printf("cels \t fahr\n");

	for (int cels = LOWER; cels <= UPPER; cels += STEP) {
		float fahr = (9.0 * cels / 5.0) + 32;
		printf("%d\t%.1f\n", cels, fahr);
	}
}
