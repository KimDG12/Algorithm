#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "prim_sort.h"

Graph2* initializeGraph(int V) {
    Graph2* g = (Graph2*)malloc(sizeof(Graph2));
    g->num_vertices = V;
    // �׷����� ���� ����� �������� �Ҵ��ϰ� 0���� �ʱ�ȭ
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
    int* parent = (int*)(g->num_vertices * sizeof(int)); // �ּ� ���� Ʈ���� ������ �迭
    int* key = (int*)(g->num_vertices * sizeof(int));    // ������ Ű ���� ������ �迭
    int* mstSet = (int*)(g->num_vertices * sizeof(int)); // �ּ� ���� Ʈ���� ���Ե� ������ ǥ���ϴ� �迭
    // �ʱ�ȭ
    for (int i = 0; i < g->num_vertices; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }
    key[0] = 0;     // ���� ������ Ű ���� 0���� ����
    parent[0] = -1; // ���� ������ �ּ� ���� Ʈ���� ��Ʈ
    // �ּ� ���� Ʈ�� ����
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
    // ��� ���
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