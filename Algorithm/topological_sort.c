#include "topological_sort.h"

// 그래프 초기화 함수
void initGraph(Graph3* graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; ++i) {
        graph->adjList[i] = NULL;
        graph->inDegree[i] = 0;
    }
}

// 간선 추가 함수
void addEdge3(Graph3* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    graph->inDegree[dest]++;
}

// 위상 정렬 함수
void topological_sort(Graph3* graph) {
    int stack[MAX_VERTICES];
    int top = -1;
    // 진입 차수가 0인 정점을 스택에 삽입
    for (int i = 0; i < graph->vertices; ++i) {
        if (graph->inDegree[i] == 0) {
            stack[++top] = i;
        }
    }
    while (top != -1) {
        int currentVertex = stack[top--];
        printf("%d ", currentVertex);
        // 현재 정점과 연결된 정점의 진입 차수를 감소
        Node* temp = graph->adjList[currentVertex];
        while (temp != NULL) {
            int adjacentVertex = temp->vertex;
            graph->inDegree[adjacentVertex]--;
            // 진입 차수가 0이 되면 스택에 삽입
            if (graph->inDegree[adjacentVertex] == 0) {
                stack[++top] = adjacentVertex;
            }
            temp = temp->next;
        }
    }
}