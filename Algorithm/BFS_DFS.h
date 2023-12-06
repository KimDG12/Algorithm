#pragma once

typedef struct Graph {
	int num;
	int** matrix;
	int* visit;
}Graph;
Graph* makeGraph(int num);
void addEdge(Graph* graph, int start, int end);
void printGraph(Graph* graph);
void BFS(Graph* graph, int vertex);
void DFS(Graph* graph, int vertex);
void print_BFS();
void print_DFS();