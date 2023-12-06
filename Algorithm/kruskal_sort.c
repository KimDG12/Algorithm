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
    int e = 0; // 결과 트리에 포함된 간선의 개수
    int i = 0; // 간선 배열을 탐색할 인덱스
    // 간선을 가중치의 오름차순으로 정렬
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);
    // 부분 집합을 초기화
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    makeSet(subsets, V);
    // 최소 신장 트리를 구성
    while (e < V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        // 사이클을 형성하지 않으면 결과 트리에 간선 추가
        if (x != y) {
            result[e++] = next_edge;
            unionSets(subsets, x, y);
        }
    }
    // 결과 트리 출력
    printf("최소 신장 트리:\n");
    for (i = 0; i < e; ++i)
        printf("%d - %d: %d\n", result[i].src, result[i].dest, result[i].weight);
    free(subsets);
}
