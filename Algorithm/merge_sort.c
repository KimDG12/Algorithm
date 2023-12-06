#include "merge_sort.h"
#include "gotoxy.h"

void merge(int arr[], int left, int middle, int right) {
	int i, j, k = left;
	int n1 = middle - left + 1;
	int n2 = right - middle;
	int* L = (int*)malloc(n1 * sizeof(int));
	int* R = (int*)malloc(n2 * sizeof(int));
	for (i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[middle + 1 + j];
	}
	i = 0, j = 0;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
	free(L);
	free(R);
}

void merge_sort(int arr[], int left, int right) {
	if (left < right) {
		int middle = left + (right - left) / 2;
		merge_sort(arr, left, middle);
		merge_sort(arr, middle + 1, right);
		merge(arr, left, middle, right);
		printf("배열 단계: ");
		for (int i = left; i <= right; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
}

void print_merge() {
	int x = 0, y = 0;
	gotoxy(x, y);
	printf("void merge(int arr[], int left, int middle, int right) {\n");
	gotoxy(x, y + 1);
	printf("   int i, j, k = left, n1 = middle - left + 1, n2 = right - middle;\n");
	gotoxy(x, y + 2);
	printf("   int* L = (int*)malloc(n1 * sizeof(int));\n");
	gotoxy(x, y + 3);
	printf("   int* R = (int*)malloc(n2 * sizeof(int));\n");
	gotoxy(x, y + 4);
	printf("   for (i = 0; i < n1; i++) { L[i] = arr[left + i]; }\n");
	gotoxy(x, y + 5);
	printf("   for (j = 0; j < n2; j++) { R[j] = arr[middle + 1 + j]; }\n");
	gotoxy(x, y + 6);
	printf("   i = 0, j = 0;\n");
	gotoxy(x, y + 7);
	printf("   while (i < n1 && j < n2) {\n");
	gotoxy(x, y + 8);
	printf("      if (L[i] <= R[j]) {\n");
	gotoxy(x, y + 9);
	printf("         arr[k] = L[i];\n");
	gotoxy(x, y + 10);
	printf("         i++;\n");
	gotoxy(x, y + 11);
	printf("      }\n");
	gotoxy(x, y + 12);
	printf("      else {\n");
	gotoxy(x, y + 13);
	printf("         arr[k] = R[j];\n");
	gotoxy(x, y + 14);
	printf("         j++;\n");
	gotoxy(x, y + 15);
	printf("      }\n");
	gotoxy(x, y + 16);
	printf("      k++; \n");
	gotoxy(x, y + 17);
	printf("   }\n");
	gotoxy(x, y + 18);
	printf("   while (i < n1) {\n");
	gotoxy(x, y + 19);
	printf("      arr[k] = L[i];\n");
	gotoxy(x, y + 20);
	printf("      i++;\n");
	gotoxy(x, y + 21);
	printf("      k++;\n");
	gotoxy(x, y + 22);
	printf("   }\n");
	gotoxy(x, y + 23);
	printf("   while (j < n2) {\n");
	gotoxy(x, y + 24);
	printf("      arr[k] = R[j];\n");
	gotoxy(x, y + 25);
	printf("      j++;\n");
	gotoxy(x, y + 26);
	printf("      k++;\n");
	gotoxy(x, y + 27);
	printf("   }\n");
	gotoxy(x, y + 28);
	printf("}\n\n");
	gotoxy(x, y + 29);
	printf("void merge_sort(int arr[], int left, int right) {\n");
	gotoxy(x, y + 30);
	printf("   if (left < right) {\n");
	gotoxy(x, y + 31);
	printf("      int middle = left + (right - left) / 2;\n");
	gotoxy(x, y + 32);
	printf("      merge_sort(arr, left, middle);\n");
	gotoxy(x, y + 33);
	printf("      merge_sort(arr, middle + 1, right);\n");
	gotoxy(x, y + 34);
	printf("      merge(arr, left, middle, right);\n");
	gotoxy(x, y + 35);
	printf("   }\n");
	gotoxy(x, y + 36);
	printf("}\n");
}