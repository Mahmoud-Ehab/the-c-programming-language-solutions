/*
	Our binary search makes two tests inside the loop, when one would 
	suffice (at the price of more tests outside). Write a version with 
	only one test inside the loop and measure the difference in run-time.
*/

#include <stdio.h>

#define LIST_SIZE 1000

int binsearch(int number, int list[], int list_size, int iterations[]);
int binsearchV2(int number, int list[], int list_size, int iterations[]);
void arrDisplay(int arr[], int from, int to);

int main() {
	int x = 450;
	int v[LIST_SIZE];
	for (int i = 0; i < LIST_SIZE; i++) 
		v[i] = i;
	
	int it1[1];
	int it2[1];

	// Trying binsearch
	printf("binsearch:\n");
	printf("\tFound the number: %d\n", x);
	printf("\tin the array: "); arrDisplay(v, 0, LIST_SIZE);
	printf("\tat index: %d\n", binsearch(x, v, LIST_SIZE, it1));
	
	// Trying binsearchV2
	printf("binsearchV2:\n");
	printf("\tFound the number: %d\n", x);
	printf("\tin the array: "); arrDisplay(v, 0, LIST_SIZE);
	printf("\tat index: %d\n", binsearchV2(x, v, LIST_SIZE, it2));
	
	// Display measurements
	printf("binsearch took %d iterations with 2 comparisons.\n", it1[0]);
	printf("binsearchV2 took %d iterations with 1 comparison.\n", it2[0]);

	return 0;
}

/* find x in v[0] <= v[1] <= v[2] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n, int iterations[1]) {
	int low, mid, high;

	low = 0;
	high = n - 1;

	iterations[0] = 0;
	while (low <= high) {
		iterations[0]++;
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else 
			return mid;
	}

	return -1;
}

int binsearchV2(int x, int v[], int n, int iterations[1]) {
	int low, mid, high;

	low = 0;
	high = n - 1;
	iterations[0] = 0;
	
	while (low < high) {
		iterations[0]++;
		mid = (low + high) / 2;
		if (x > v[mid])
			low = mid + 1;
		else
			high = mid;
	}

	return x == v[low] ? low : -1;
}

void arrDisplay(int arr[], int from, int to) {
	int limit = 10;
	int counter = 0;

	printf("[");
	for (int i = from; i < to-1; i++, counter++) {
		if (counter >= limit) {
			printf("..., %d]\n", arr[to-1]);
			return;
		}
		printf("%d, ", arr[i]);
	}

	printf("%d]\n", arr[to-1]);
}


