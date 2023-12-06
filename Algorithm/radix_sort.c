#include <stdio.h>
#include "radix_sort.h"
#include "LinkedQueue.h"
#include "gotoxy.h"
#define RADIX 10
#define DIGIT 2

void radix_sort(int arr[], int size) {
    int i, j, bucket, d, factor = 1;
    LQueueType* Q[RADIX];
    for (bucket = 0; bucket < RADIX; bucket++) {
        Q[bucket] = createLinkedQueue();
    }
    for (d = 0; d < DIGIT; d++) {
        for (i = 0; i < size; i++)
            enLQueue(Q[(arr[i] / factor) % 10], arr[i]);
        for (bucket = 0, i = 0; bucket < RADIX; bucket++) {
            while (!isLQEmpty(Q[bucket]))
                arr[i++] = deLQueue(Q[bucket]);
        }
        factor = factor * 10;
        printf("\n %d ´Ü°è : ", d + 1);
        for (i = 0; i < size; i++) printf(" %d", arr[i]);
    }
    printf("\n");
}

void print_radix() {
	int x = 0, y = 0;
	gotoxy(x, y);
	printf("void radix_sort(int arr[], int size) {\n");
	gotoxy(x, y + 1);
	printf("   int i, j, bucket, d, factor = 1;\n");
	gotoxy(x, y + 2);
	printf("   LQueueType* Q[RADIX];\n");
	gotoxy(x, y + 3);
	printf("   for (bucket = 0; bucket < RADIX; bucket++) { Q[bucket] = createLinkedQueue(); }\n");
	gotoxy(x, y + 4);
	printf("   for (d = 0; d < DIGIT; d++) {\n");
	gotoxy(x, y + 5);
	printf("      for (i = 0; i < size; i++) { enLQueue(Q[(arr[i] / factor) % 10], arr[i]); }\n");
	gotoxy(x, y + 6);
	printf("      for (bucket = 0, i = 0; bucket < RADIX; bucket++) { while (!isLQEmpty(Q[bucket])) { arr[i++] = deLQueue(Q[bucket]); } }\n");
	gotoxy(x, y + 7);
	printf("      factor = factor * 10;\n");
	gotoxy(x, y + 8);
	printf("   }\n");
	gotoxy(x, y + 9);
	printf("}\n");
}