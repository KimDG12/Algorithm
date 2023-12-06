#pragma once

struct Edge {
	int src, dest, weight;
};
struct Graph1 {
	int V, E;
	struct Edge* edges;
};
struct Subset {
	int parent, rank;
};

void makeSet(struct Subset subset[], int V);
int find(struct Subset subsets[], int i);
void unionSets(struct Subset subsets[], int x, int y);
int compareEdges(const void* a, const void* b);
void kruskal_sort(struct Graph1* graph);