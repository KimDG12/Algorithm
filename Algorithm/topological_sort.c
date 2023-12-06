#include "topological_sort.h"

// �׷��� �ʱ�ȭ �Լ�
void initGraph(Graph3* graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; ++i) {
        graph->adjList[i] = NULL;
        graph->inDegree[i] = 0;
    }
}

// ���� �߰� �Լ�
void addEdge3(Graph3* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    graph->inDegree[dest]++;
}

// ���� ���� �Լ�
void topological_sort(Graph3* graph) {
    int stack[MAX_VERTICES];
    int top = -1;
    // ���� ������ 0�� ������ ���ÿ� ����
    for (int i = 0; i < graph->vertices; ++i) {
        if (graph->inDegree[i] == 0) {
            stack[++top] = i;
        }
    }
    while (top != -1) {
        int currentVertex = stack[top--];
        printf("%d ", currentVertex);
        // ���� ������ ����� ������ ���� ������ ����
        Node* temp = graph->adjList[currentVertex];
        while (temp != NULL) {
            int adjacentVertex = temp->vertex;
            graph->inDegree[adjacentVertex]--;
            // ���� ������ 0�� �Ǹ� ���ÿ� ����
            if (graph->inDegree[adjacentVertex] == 0) {
                stack[++top] = adjacentVertex;
            }
            temp = temp->next;
        }
    }
}