#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Quicksort written by Martin Wass.
 *
 */

// Print a representation of an array.
void printArray(int* array, int arraySize){
	printf("[");
	for(int i = 0; i < arraySize-1; i++){
		printf("%d,", array[i]);
	}
	printf("%d]\n", array[arraySize-1]);
}

// Swap values at indexes a and b in array.
void swapArray(int*array, int a, int b){
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

// Sort the subarray from (including) "from" to (excluding) "to".
void quicksort(int* array, int from, int to){

	// If there is one or zero elements to sort we may return since list is sorted already.
	if(to - from <= 1){
		return;
	}

	int randomIndex = from + rand()%(to-from); // Choose a random pivot which needs to be somewhere in the sorting range.
	int pivotValue = array[randomIndex];
	swapArray(array, randomIndex, to-1); // Place pivot last in subarray
	// Partition array with Lomuto partition scheme
	int i = from-1;
	int j;
	for(j = from; j < to-1; j++){
		if(array[j] < pivotValue){
			i++;
			swapArray(array, i, j);
		}
	}
	swapArray(array, i+1, to-1);

	// Sort elements which were respectively less than and greater than pivot.
	quicksort(array, from, i+1);
	quicksort(array, i+2, to);
}

// Create and sort list while printing info to user.
int main(){
	srand(time(NULL)); // Initialize random number generator.
	int listSize = 30;
	int list[listSize];
	// Fill array with random numbers 0-9.
	for(int i = 0; i < listSize; i++){
		list[i] = rand()%10;
	}

	printf("UNSORTED ARRAY: ");
	printArray(list, listSize);

	// Sort array.
	quicksort(list, 0, listSize);

	printf("ARRAY AFTER QUICKSORT: ");
	printArray(list, listSize);

	return 0;
}
