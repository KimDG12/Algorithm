#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "prim_sort.h"

Graph2* initializeGraph(int V) {
    Graph2* g = (Graph2*)malloc(sizeof(Graph2));
    g->num_vertices = V;
    // 그래프의 인접 행렬을 동적으로 할당하고 0으로 초기화
    g->graph = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        g->graph[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            g->graph[i][j] = 0;
        }
    }
    return g;
}

void addEdge1(Graph2* g, int src, int dest, int weight) {
    g->graph[src][dest] = weight;
    g->graph[dest][src] = weight;
}

int minKey(int key[], int mstSet[], int V) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(Graph2* g) {
    int* parent = (int*)(g->num_vertices * sizeof(int)); // 최소 신장 트리를 저장할 배열
    int* key = (int*)(g->num_vertices * sizeof(int));    // 정점의 키 값을 저장할 배열
    int* mstSet = (int*)(g->num_vertices * sizeof(int)); // 최소 신장 트리에 포함된 정점을 표시하는 배열
    // 초기화
    for (int i = 0; i < g->num_vertices; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }
    key[0] = 0;     // 시작 정점의 키 값을 0으로 설정
    parent[0] = -1; // 시작 정점은 최소 신장 트리의 루트
    // 최소 신장 트리 구성
    for (int count = 0; count < g->num_vertices - 1; count++) {
        int u = minKey(key, mstSet, g->num_vertices);
        mstSet[u] = 1;
        for (int v = 0; v < g->num_vertices; v++) {
            if (g->graph[u][v] && mstSet[v] == 0 && g->graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = g->graph[u][v];
            }
        }
    }
    // 결과 출력
    printf("Edge \tWeight\n");
    for (int i = 1; i < g->num_vertices; i++) {
        printf("%d - %d \t%d\n", parent[i], i, g->graph[i][parent[i]]);
    }
}

void freeGraph(Graph2* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        free(g->graph[i]);
    }
    free(g->graph);
    free(g);
}