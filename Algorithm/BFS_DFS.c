#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "circle_q.h"
#include "BFS_DFS.h"
#include "gotoxy.h"

Graph* makeGraph(int num) {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->matrix = (int**)malloc(sizeof(int*) * num);
	graph->visit = (int*)malloc(sizeof(int) * num);
	graph->num = num;
	for (int i = 0; i < num; i++) {
		graph->matrix[i] = (int*)malloc(sizeof(int) * num);
		memset(graph->matrix[i], 0, sizeof(int) * num);
		graph->visit[i] = 0;
	}
	return graph;
}

void makeNewGraph(Graph* graph) {
	int start, end;
	for (int i = 0; i < graph->num; i++) {
		printf("%d단계(시작과 끝 입력) : ", i);
		scanf_s("%d %d", &start, &end);
		addEdge(graph, start, end);
	}
}

void addEdge(Graph* graph, int start, int end)
{
	graph->matrix[start][end] = 1;
	graph->matrix[end][start] = 1;
}

void printGraph(Graph* graph) {
	for (int i = 0; i < graph->num; i++) {
		printf("시작 %d ->", i);
		for (int j = 0; j < graph->num; j++) {
			printf("%d ", graph->matrix[i][j]);
		}
		printf("\n");
	}
}

void BFS(Graph* graph, int vertex) {
	Circle_Queue q;
	init_q(&q);
	enqueue(&q, vertex);
	printf("정점 %d가 방문되었습니다\n", vertex);
	while (!is_empty(&q)) {
		vertex = dequeue(&q);
		for (int i = vertex; i < graph->num; i++) {
			if (!graph->visit[i] && graph->matrix[vertex][i] == 1) {
				graph->visit[i] = 1;
				enqueue(&q, i);
				printf("정점 %d가 방문되었습니다\n", i);
			}
		}
	}
}

void DFS(Graph* graph, int vertex) {
	graph->visit[vertex] = 1;
	printf("정점 %d가 방문되었습니다\n", vertex);
	for (int i = 0; i < graph->num; i++) {
		if (graph->matrix[vertex][i] == 1 && graph->visit[i] == 0) {
			DFS(graph, i);
		}
	}
}

void print_BFS() {
	int x = 0, y = 0;
	gotoxy(x, y);
	printf("void BFS(Graph* graph, int vertex) {\n");
	gotoxy(x, y + 1);
	printf("   Circle_Queue q;\n");
	gotoxy(x, y + 2);
	printf("   init_q(&q);\n");
	gotoxy(x, y + 3);
	printf("   enqueue(&q, vertex);\n");
	gotoxy(x, y + 4);
	printf("   while (!is_empty(&q)) {\n");
	gotoxy(x, y + 5);
	printf("      vertex = dequeue(&q);\n");
	gotoxy(x, y + 6);
	printf("      for (int i = vertex; i < graph->num; i++) {\n");
	gotoxy(x, y + 7);
	printf("         if (!graph->visit[i] && graph->matrix[vertex][i] == 1) {\n");
	gotoxy(x, y + 8);
	printf("            graph->visit[i] = 1;\n");
	gotoxy(x, y + 9);
	printf("            enqueue(&q, i);\n");
	gotoxy(x, y + 10);
	printf("         }\n");
	gotoxy(x, y + 11);
	printf("      }\n");
	gotoxy(x, y + 12);
	printf("   }\n");
	gotoxy(x, y + 13);
	printf("}\n");
}

void print_DFS() {
	int x = 0, y = 0;
	gotoxy(x, y);
	printf("void DFS(Graph* graph, int vertex) {\n");
	gotoxy(x, y + 1);
	printf("   graph->visit[vertex] = 1;\n");
	gotoxy(x, y + 2);
	printf("   for (int i = 0; i < graph->num; i++) {\n");
	gotoxy(x, y + 3);
	printf("      if (graph->matrix[vertex][i] == 1 && graph->visit[i] == 0) {\n");
	gotoxy(x, y + 4);
	printf("         DFS(graph, i);\n");
	gotoxy(x, y + 5);
	printf("      }\n");
	gotoxy(x, y + 6);
	printf("   }\n");
	gotoxy(x, y + 7);
	printf("}\n");
}