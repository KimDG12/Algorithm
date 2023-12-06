#include <stdio.h>
#include <stdlib.h>
#include "kruskal_sort.h"

void makeSet(struct Subset subsets[], int V) {
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
}

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskal_sort(struct Graph1* graph) {
    int V = graph->V;
    struct Edge* result = (struct Edge*)malloc(V * sizeof(struct Edge));
    int e = 0; // ��� Ʈ���� ���Ե� ������ ����
    int i = 0; // ���� �迭�� Ž���� �ε���
    // ������ ����ġ�� ������������ ����
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);
    // �κ� ������ �ʱ�ȭ
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    makeSet(subsets, V);
    // �ּ� ���� Ʈ���� ����
    while (e < V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        // ����Ŭ�� �������� ������ ��� Ʈ���� ���� �߰�
        if (x != y) {
            result[e++] = next_edge;
            unionSets(subsets, x, y);
        }
    }
    // ��� Ʈ�� ���
    printf("�ּ� ���� Ʈ��:\n");
    for (i = 0; i < e; ++i)
        printf("%d - %d: %d\n", result[i].src, result[i].dest, result[i].weight);
    free(subsets);
}
