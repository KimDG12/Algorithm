#include "circle_q.h"

void init_q(Circle_Queue* q) {
	q->front = q->rear = 0;
}

bool is_empty(Circle_Queue* q) {
	if (q->front == q->rear) {
		return true;
	}
	else {
		return false;
	}
}

bool is_full(Circle_Queue* q) {
	if ((q->rear + 1) % MAX_SIZE == q->front) {
		return true;
	}
	else {
		return false;
	}
}

void enqueue(Circle_Queue* q, int element) {
	if (is_full(q) == true) {
		return;
	}
	else {
		q->rear = (q->rear + 1) % MAX_SIZE;
		q->c_queue[q->rear] = element;
	}
}

int dequeue(Circle_Queue* q) {
	if (is_empty(q) == true) {
		return 0;
	}
	else {
		q->front = (q->front + 1) % MAX_SIZE;
		return q->c_queue[q->front];
	}
}