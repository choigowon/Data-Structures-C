#include <stdio.h>

void bubbleSort(int* arr, int size) {
	int i, j, temp;
	for (i = 0; i < size - 1; i++) { // pass
		for (j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void selectionSort(int* arr, int size) {
	int i, j, min, temp;
	for (i = 0; i < size - 1; i++) { // pass
		min = i;
		for (j = i + 1; j < size; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		temp = arr[j];
		arr[j] = arr[min];
		arr[min] = temp;
	}
}

int main() {

}
