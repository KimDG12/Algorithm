#include <stdio.h>
#include "selection_sort.h"
#include "gotoxy.h"

void selection_sort(int arr[], int size) {
    int i, j, k, min, temp;
    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        printf("\n");
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
        printf("´Ü°è %d: ", i + 1);
        for (k = 0; k < size; k++) {
            printf("%d ", arr[k]);
        }
    }
}

void print_selection() {
	int x = 0, y = 0;
	gotoxy(x, y);
	printf("void selection_sort(int arr[], int size) {\n");
	gotoxy(x, y + 1);
	printf("   int i, j, k, min, temp;\n");
	gotoxy(x, y + 2);
	printf("   for (i = 0; i < size - 1; i++) {\n");
	gotoxy(x, y + 3);
	printf("      min = i;\n");
	gotoxy(x, y + 4);
	printf("      for (j = i + 1; j < size; j++) {\n");
	gotoxy(x, y + 5);
	printf("         if (arr[j] < arr[min])\n");
	gotoxy(x, y + 6);
	printf("            min = j;\n");
	gotoxy(x, y + 7);
	printf("      temp = arr[min];\n");
	gotoxy(x, y + 8);
	printf("      arr[i] = temp;\n");
	gotoxy(x, y + 9);
	printf("   }\n");
	gotoxy(x, y + 10);
	printf("}\n");
}