#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define ROWS 5
#define COLS 5

typedef struct {
	int row;
	int col;
} Point;

typedef struct {
	Point point;
	double f;
	double g;
	double h;
	struct Node* parent;
} Node4;

double heuristic(Point a, Point b);
Node4* createNode(Point point, double g, double h, Node4* parent);
int findMinF(Node4** openSet, int openSetSize);
void removeFromOpenSet(Node4** openSet, int* openSetSize, int index);
bool isInOpenSet(Node4** openSet, int openSetSize, Point point);
void printPath(Node4* endNode);
void aStar(Point start, Point goal);