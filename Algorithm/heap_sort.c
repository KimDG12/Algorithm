#include <stdio.h>
#include "heap_sort.h"
#include "gotoxy.h"

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heap(int arr[], int size, int i) {
	int temp;
	int large = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < size && arr[left] > arr[large]) large = left;
	if (right < size && arr[right > arr[large]]) large = right;
	if (large != i) {
		swap(&arr[i], &arr[large]);
		heap(arr, size, large);
	}
}

void heap_sort(int arr[], int size) {
	int i, j, temp;
	for (i = size / 2 - 1; i >= 0; i--) {
		heap(arr, size, i);
	}
	for (i = size - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]);
		heap(arr, i, 0);
		printf("배열 단계: ");
		for (int j = 0; j < size; j++) {
			printf("%d ", arr[j]);
		}
		printf("\n");
	}
	printf("결과: ");
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
}

void print_heap() {
	int x = 0, y = 0;
	gotoxy(x, y);
	printf("void heap(int arr[], int size, int i) {\n");
	gotoxy(x, y + 1);
	printf("   int temp, large = i, left = 2 * i + 1, right = 2 * i + 2;\n");
	gotoxy(x, y + 2);
	printf("   if (left < size && arr[left] > arr[large]) large = left;\n");
	gotoxy(x, y + 3);
	printf("   if (right < size && arr[right > arr[large]]) large = right;\n");
	gotoxy(x, y + 4);
	printf("   if (large != i) {\n");
	gotoxy(x, y + 5);
	printf("      swap(&arr[i], &arr[large]);\n");
	gotoxy(x, y + 6);
	printf("      heap(arr, size, large);\n");
	gotoxy(x, y + 7);
	printf("   }\n");
	gotoxy(x, y + 8);
	printf("}\n");
	gotoxy(x, y + 9);
	printf("void heap_sort(int arr[], int size) {\n");
	gotoxy(x, y + 10);
	printf("   int i, j, temp;\n");
	gotoxy(x, y + 11);
	printf("   for (i = size / 2 - 1; i >= 0; i--) { heap(arr, size, i); }\n");
	gotoxy(x, y + 12);
	printf("   for (i = size - 1; i > 0; i--) {\n");
	gotoxy(x, y + 13);
	printf("      swap(&arr[0], &arr[i]);\n");
	gotoxy(x, y + 14);
	printf("      heap(arr, i, 0);\n");
	gotoxy(x, y + 15);
	printf("   }\n");
	gotoxy(x, y + 16);
	printf("}\n");
}