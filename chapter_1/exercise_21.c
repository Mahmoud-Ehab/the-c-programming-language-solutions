/* Write a program 'entab' that replaces strings of blanks by the minimum number of tabs
 * and blanks to achieve the same spacing. Use the tab stops as for detab. When either a
 * tab or a single blank would suffice to reach a tab stop, which should be given preference? */

#include <stdio.h>

void entab(int tabsize, int numOfBlanks);

int main() {
	int tabsize = 4;
	int conBlanksNum = 0;
	int c;
	
	printf("(CTRL + D for EOF)\n");

	while ((c = getchar()) != EOF) {
		if (c == ' ') conBlanksNum++;
		else {
			entab(tabsize, conBlanksNum);
			conBlanksNum = 0;
			putchar(c);
		}
	}

	return 0;
}

void entab(int tabsize, int blanksNum) {
	if (blanksNum <= 0) return;

	if (blanksNum < tabsize) {
		for (int i = 0; i < blanksNum; i++) 
			putchar(' ');
		return;
	}

	for (int i = 0; i < blanksNum / tabsize; i++) 
		putchar('\t');
	for (int i = 0; i < blanksNum % tabsize; i++) 
		putchar(' ');
}
