#include <stdio.h>
#include "quick_sort.h"
#include "gotoxy.h"

int partition(int arr[], int low, int high) {
	int piv = arr[high];
	int i = low - 1;
	int j, temp;
	for (j = low; j <= high - 1; j++) {
		if (arr[j] < piv) {
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return(i + 1);
}

void quick_sort(int arr[], int low, int high) {
	if (low < high) {
		int part = partition(arr, low, high);
		printf("정렬된 위치의 피벗 요소: %d\n", arr[part]);
		printf("배열 단계 (피벗=%d): ", arr[part]);
		for (int i = low; i <= high; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		quick_sort(arr, low, part - 1);
		quick_sort(arr, part + 1, high);
	}
}

void print_quick() {
	int x = 0, y = 0;
	gotoxy(x, y);
	printf("int partition(int arr[], int low, int high) {\n");
	gotoxy(x, y + 1);
	printf("   int piv = arr[high], i = low - 1, j, temp;\n");
	gotoxy(x, y + 2);
	printf("   for (j = low; j <= high - 1; j++) {\n");
	gotoxy(x, y + 3);
	printf("      if (arr[j] < piv) {\n");
	gotoxy(x, y + 4);
	printf("         i++;\n");
	gotoxy(x, y + 5);
	printf("         temp = arr[i];\n");
	gotoxy(x, y + 6);
	printf("         arr[i] = arr[j];\n");
	gotoxy(x, y + 7);
	printf("         arr[j] = temp;\n");
	gotoxy(x, y + 8);
	printf("      }\n");
	gotoxy(x, y + 9);
	printf("   }\n");
	gotoxy(x, y + 10);
	printf("   temp = arr[i + 1];\n");
	gotoxy(x, y + 11);
	printf("   arr[i + 1] = arr[high];\n");
	gotoxy(x, y + 12);
	printf("   arr[high] = temp;\n");
	gotoxy(x, y + 13);
	printf("   return(i + 1);\n");
	gotoxy(x, y + 14);
	printf("}\n");
	gotoxy(x, y + 15);
	printf("void quick_sort(int arr[], int low, int high) {\n");
	gotoxy(x, y + 16);
	printf("   if (low < high) {\n");
	gotoxy(x, y + 17);
	printf("      int part = partition(arr, low, high);\n");
	gotoxy(x, y + 18);
	printf("      quick_sort(arr, low, part - 1);\n");
	gotoxy(x, y + 19);
	printf("      quick_sort(arr, part + 1, high);\n");
	gotoxy(x, y + 20);
	printf("   }\n");
	gotoxy(x, y + 21);
	printf("}\n");
}