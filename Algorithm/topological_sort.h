#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node* adjList[MAX_VERTICES];
    int inDegree[MAX_VERTICES];
    int vertices;
} Graph3;

void initGraph3(Graph3* graph, int vertices);
void addEdge3(Graph3* graph, int src, int dest);
void topological_sort(Graph3* graph);