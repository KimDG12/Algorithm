#include <stdio.h>
#include "insertion_sort.h"
#include "gotoxy.h"

void shift(int arr[], int i, int j) {
	int temp = arr[j];
	while (j > i) {
		arr[j] = arr[j - 1];
		j--;
	}
	arr[i] = temp;
}

void insertion_sort(int arr[], int size) {
	int i, j, k, temp;
	for (i = 1; i < size; i++) {
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > temp) {
			j--;
		}
		shift(arr, j + 1, i);
		printf("단계 %d: ", i);
		for (int k = 0; k < size; k++) {
			printf("%d ", arr[k]);
		}
		printf("\n");
	}
	printf("결과: ");
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void print_insertion() {
	int x = 0, y = 0;
	gotoxy(x, y);
	printf("void shift(int arr[], int i, int j) {\n");
	gotoxy(x, y + 1);
	printf("   int temp = arr[j];\n");
	gotoxy(x, y + 2);
	printf("   while (j > i) {\n");
	gotoxy(x, y + 3);
	printf("      arr[j] = arr[j - 1];\n");
	gotoxy(x, y + 4);
	printf("      while (j >= 0 && arr[j] > temp) { j--; }\n");
	gotoxy(x, y + 5);
	printf("      j--;\n");
	gotoxy(x, y + 6);
	printf("   }\n");
	gotoxy(x, y + 7);
	printf("   arr[i] = temp;\n");
	gotoxy(x, y + 8);
	printf("}\n\n");
	gotoxy(x, y + 9);
	printf("void insertion_sort(int arr[], int size) {\n");
	gotoxy(x, y + 10);
	printf("   int i, j, k, temp;\n");
	gotoxy(x, y + 11);
	printf("   for (i = 1; i < size; i++) {\n");
	gotoxy(x, y + 12);
	printf("      temp = arr[i];\n");
	gotoxy(x, y + 13);
	printf("      j = i - 1;\n");
	gotoxy(x, y + 14);
	printf("      while (j >= 0 && arr[j] > temp) { j--; }\n");
	gotoxy(x, y + 15);
	printf("      shift(arr, j + 1, i);\n");
	gotoxy(x, y + 16);
	printf("   }\n");
	gotoxy(x, y + 17);
	printf("}\n");
}