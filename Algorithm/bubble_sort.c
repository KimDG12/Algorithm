#include "bubble_sort.h"
#include "gotoxy.h"

void bubble_sort(int arr[], int size) {
	int i, j, k, temp;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				printf("단계 %d: ", i + 1);
				for (k = 0; k < size; k++) {
					printf("%d ", arr[k]);
				}
				printf("\n");
			}
		}
	}
	printf("결과: ");
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void print_bubble() {
	int x = 0, y = 0;
	gotoxy(x, y);
	printf("void bubble_sort(int arr[], int size) {\n");
	gotoxy(x, y + 1);
	printf("   int i, j, k, temp;\n");
	gotoxy(x, y + 2);
	printf("   for (i = 0; i < size - 1; i++) {\n");
	gotoxy(x, y + 3);
	printf("      for (j = 0; j < size - i - 1; j++) {\n");
	gotoxy(x, y + 4);
	printf("         if (arr[j] > arr[j + 1]) {\n");
	gotoxy(x, y + 5);
	printf("            temp = arr[j];\n");
	gotoxy(x, y + 6);
	printf("            arr[j] = arr[j + 1];\n");
	gotoxy(x, y + 7);
	printf("         }\n");
	gotoxy(x, y + 8);
	printf("      }\n");
	gotoxy(x, y + 9);
	printf("   }\n");
	gotoxy(x, y + 10);
	printf("}\n");
}