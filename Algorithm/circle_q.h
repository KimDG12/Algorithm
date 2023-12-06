#pragma once
#define MAX_SIZE 10
#include <stdio.h>
#include <stdbool.h>

typedef struct circle_Queue {
	int c_queue[MAX_SIZE];
	int front, rear;
}Circle_Queue;
void init_q(Circle_Queue* q);
bool is_empty(Circle_Queue* q);
bool is_full(Circle_Queue* q);
void enqueue(Circle_Queue* q, int element);
int dequeue(Circle_Queue* q);