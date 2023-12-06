#pragma once
#define MAX_VERTICES 100
#define INF INT_MAX

typedef struct {
	int** graph;
	int num_vertices;
} Graph2;

int minKey(int key[], int mstSet[], int V);
void primMST(Graph2* g);
void addEdge1(Graph2* g, int src, int dest, int weight);
void freeGraph(Graph2* g);
Graph2* initializeGraph(int V);