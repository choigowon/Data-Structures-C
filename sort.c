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

int main() {

}
