#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* arr, int size) { // O(N ^ 2)
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

void insertionSort(int* arr, int size) {
	int i, j, temp;
	for (i = 1; i < size; i++) {
		temp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > temp; j--) {
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}

void quickSort(int* arr, int left, int right) { // O(N log N)
	int pl = left, pr = right, pivot = arr[(pl + pr) / 2], temp;
	do {
		while (arr[pl] < pivot)
			pl++;
		while (arr[pr] > pivot)
			pr--;
		if (pl <= pr) {
			temp = arr[pl];
			arr[pl] = arr[pr];
			arr[pr] = temp;
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (left < pr)
		quickSort(arr, left, pr);
	if (pl < right)
		quickSort(arr, pl, right);
}

void merge(int* arr1, int size1, int* arr2, int size2, int* arrMerge) {
	int idx1, idx2, idxM;
	idx1 = idx2 = idxM = 0;
	while (idx1 < size1 && idx2 < size2) {
		if (arr1[idx1] < arr2[idx2]) {
			arrMerge[idxM] = arr1[idx1];
			idx1++;
			idxM++;
		}
		else {
			arrMerge[idxM] = arr2[idx2];
			idx2++;
			idxM++;
		}
	}
	while (idx1 < size1)
		arrMerge[idxM++] = arr1[idx1++];
	while (idx2 < size2)
		arrMerge[idxM++] = arr2[idx2++];
}

void merge2(int* arr, int* arrMerge, int left, int mid, int right) {
	int idx1 = left;
	int idx2 = mid + 1;
	int idxM = left;
	for (int i = left; i <= right; i++)
		arrMerge[i] = arr[i];
	while (idx1 <= mid && idx2 <= right) {
		if (arrMerge[idx1] < arrMerge[idx2])
			arr[idxM++] = arrMerge[idx1++];
		else
			arr[idxM++] = arrMerge[idx2++];
	}
	while (idx1 <= mid)
		arr[idxM++] = arrMerge[idx1++];
}

void mergeSortUtil(int* arr, int* arrMerge, int left, int right) {
	int mid;
	if (left < right) { // 원소가 1개 남을 때까지 나눈 이후 병합
		mid = (left + right) / 2;
		mergeSortUtil(arr, arrMerge, left, mid);
		mergeSortUtil(arr, arrMerge, mid + 1, right);
		merge2(arr, arrMerge, left, mid, right);
	}
}

void mergeSort(int* arr, int size) { // O(N)
	int* arrMerge = (int*)malloc(sizeof(int) * size);
	mergeSortUtil(arr, arrMerge, 0, size - 1);
	free(arrMerge);
}

void bucketSort(int* arr, int size, int range) { // O(N)
	int* bucket = (int*)calloc(range, sizeof(int));
	int i, j, index = 0;
	for (i = 0; i < size; i++) {
		bucket[arr[i]]++;
	}
	for (i = 1; i < range; i++) {
		for (j = 1; j <= bucket[i]; j++) {
			arr[index++] = i;
		}
	}
	free(bucket);
}

int main() {
	int arr1[6] = { 2,4,7,9,11,15 };
	int arr2[6] = { 1,5,8,14,19,21 };
	int arrMerge[12];
	merge(arr1, 6, arr2, 6, arrMerge);
	return 0;
}
