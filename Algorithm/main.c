#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include "gotoxy.h"
#include "selection_sort.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "radix_sort.h"
#include "BFS_DFS.h"
#include "circle_q.h"
#include "kruskal_sort.h"
#include "prim_sort.h"
#include "topological_sort.h"
#include "Astar.h"
#include "backtracking.h"
#include "genetic_algorithm.h"

#define UP 0
#define DOWN 1
#define SUBMIT 4

void init();
void gotoxy();
void titleDraw();
int infoDraw();
int keyControl();
int menuDraw();
void titleDraw() {
    int x = 2;
    int y = 0;
    gotoxy(x - 2, y);
    printf("\n\n   Algorithm Project\n\n");
}
void init() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}
int menuDraw() {
    int x = 2;
    int y = 5;
    gotoxy(x - 2, y);
    printf("> 정렬 알고리즘");
    gotoxy(x, y + 1);
    printf("그래프");
    gotoxy(x, y + 2);
    printf("Prim알고리즘");
    gotoxy(x, y + 3);
    printf("Kruskal알고리즘");
    gotoxy(x, y + 4);
    printf("위상정렬");
    gotoxy(x, y + 5);
    printf("A*알고리즘");
    gotoxy(x, y + 6);
    printf("백트래킹알고리즘");
    gotoxy(x, y + 7);
    printf("유전자알고리즘");
    gotoxy(x, y + 8);
    printf("     종료    ");
    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 5) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 13) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            system("cls");
            return y - 5;
        }
        }
    }
}
int keyControl() {
    char temp = _getch();

    if (temp == 72) {
        return UP;
    }
    else if (temp == 80) {
        return DOWN;
    }
    else if (temp == ' ' || temp == 13) {
        return SUBMIT;
    }
}
int infoDraw() {
    system("cls");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("정렬 알고리즘");
    x = 5;
    y = 5;
    gotoxy(x - 2, y);
    printf("> 선택정렬");
    gotoxy(x, y + 1);
    printf("버블 절렬");
    gotoxy(x, y + 2);
    printf("퀵 정렬");
    gotoxy(x, y + 3);
    printf("삽입 정렬");
    gotoxy(x, y + 4);
    printf("병합 정렬");
    gotoxy(x, y + 5);
    printf("기수 정렬");
    gotoxy(x, y + 6);
    printf("히프 정렬");
    gotoxy(x, y + 7);
    printf("메인 메뉴");
    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 5) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 12) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            system("cls");
            return y;
        }
        }
    }
    Sleep(1000);
}
int infoDraw1() {
    system("cls");
    int x = 5;
    int y = 3;
    gotoxy(x, y);
    printf("그래프");
    x = 5;
    y = 5;
    gotoxy(x - 2, y);
    printf("> BFS정렬");
    gotoxy(x, y + 1);
    printf("DFS절렬");
    gotoxy(x, y + 2);
    printf("메인메뉴");
    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 5) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 7) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            system("cls");
            return y;
        }
        }
    }
    Sleep(1000);
}
int infoDraw2() {
    int x = 5;
    int y = 20;
    gotoxy(x - 2, y);
    printf("> 코드 보기");
    gotoxy(x, y + 1);
    printf("메인메뉴");
    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 20) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 21) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            return y;
        }
        }
    }
    Sleep(1000);
}

int main() {
    system("cls");
    system("mode con cols=100 lines=40 | title AlgorithmProject");
    int exit = 1;
    int size = 0, V = 0, n = 0;
    int v, e;
    int* s_num = (int*)malloc(size * sizeof(int));
    Graph* graph;
    graph = makeGraph(0);
    while (exit) {
        titleDraw();
        int menuNum = menuDraw();
        switch(menuNum) {
        case 0: {
            int infoNum = infoDraw();
            if (infoNum == 12) break;
            printf("배열 크기: ");
            scanf_s("%d", &size);
            printf("%d개의 숫자를 입력: ", size);
            for (int i = 0; i < size; i++) {
                scanf_s("%d", &s_num[i]);
            }
            if (infoNum == 5) {
                selection_sort(s_num, size);
                printf("\n결과: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", s_num[i]);
                }
                memset(s_num, 0, size * sizeof(int));
                int choose = infoDraw2();
                switch(choose) {
                case 20:
                    system("cls");
                    print_selection();
                    _getch();
                case 21:
                    break;
                }
                break;
            }
            else if (infoNum == 6) {
                bubble_sort(s_num, size);
                memset(s_num, 0, size * sizeof(int));
                int choose = infoDraw2();
                switch (choose) {
                case 20:
                    system("cls");
                    print_bubble();
                    _getch();
                case 21:
                    break;
                }
                break;
            }
            else if (infoNum == 7) {
                quick_sort(s_num, 0, size - 1);
                printf("결과: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", s_num[i]);
                }
                memset(s_num, 0, size * sizeof(int));
                int choose = infoDraw2();
                switch (choose) {
                case 20:
                    system("cls");
                    print_quick();
                    _getch();
                case 21:
                    break;
                }
                break;
            }
            else if (infoNum == 8) {
                insertion_sort(s_num, size);
                memset(s_num, 0, size * sizeof(int));
                int choose = infoDraw2();
                switch (choose) {
                case 20:
                    system("cls");
                    print_insertion();
                    _getch();
                case 21:
                    break;
                }
                break;
            }
            else if (infoNum == 9) {
                merge_sort(s_num, 0, size - 1);
                printf("결과: ");
                for (int i = 0; i < size; i++) printf("%d ", s_num[i]);
                printf("\n");
                memset(s_num, 0, size * sizeof(int));
                int choose = infoDraw2();
                switch (choose) {
                case 20:
                    system("cls");
                    print_merge();
                    _getch();
                case 21:
                    break;
                }
                break;
            }
            else if (infoNum == 10) {
                radix_sort(s_num, size);
                printf("결과: ");
                for (int i = 0; i < size; i++) printf("%d ", s_num[i]);
                printf("\n");
                memset(s_num, 0, size * sizeof(int));
                int choose = infoDraw2();
                switch (choose) {
                case 20:
                    system("cls");
                    print_radix();
                    _getch();
                case 21:
                    break;
                }
                break;
            }
            else if (infoNum == 11) {
                heap_sort(s_num, size);
                memset(s_num, 0, size * sizeof(int));
                int choose = infoDraw2();
                switch (choose) {
                case 20:
                    system("cls");
                    print_heap();
                    _getch();
                case 21:
                    break;
                }
                break;
            }
        }
        case 1: {
            int infoNum1 = infoDraw1();
            if (infoNum1 == 7) break;
            printf("몇 단계로 진행: ");
            scanf_s("%d", &size);
            graph = makeGraph(size);
            if (infoNum1 == 5) {
                makeNewGraph(graph);
                printGraph(graph);
                BFS(graph, 0);
                int choose = infoDraw2();
                switch (choose) {
                case 20:
                    system("cls");
                    print_BFS();
                    _getch();
                case 21:
                    break;
                }
                break;
            }
            else if (infoNum1 == 6) {
                makeNewGraph(graph);
                printGraph(graph);
                DFS(graph, 0);
                if (keyControl() == SUBMIT) {
                    system("cls");
                    break;
                }
            }
        }
        case 2: {
            printf("정점의 개수 입력: ");
            scanf_s("%d", &v);
            printf("간선의 개수 입력: ");
            scanf_s("%d", &e);
            Graph2* g = initializeGraph(v);
            printf("간선 정보 및 가중치 입력");
            int src, dest, weight;
            for (int i = 0; i < e; i++) {
                scanf_s("%d %d %d", &src, &dest, &weight);
                addEdge1(g, src, dest, weight);
            }
            primMST(g);
            freeGraph(g);
            int choose = infoDraw2();
            switch (choose) {
            case 20:
                system("cls");
                _getch();
            case 21:
                break;
            }
            break;
        }
        case 3: {
            printf("정점의 개수 입력: ");
            scanf_s("%d", &v);
            printf("간선의 개수 입력: ");
            scanf_s("%d", &e);
            struct Graph1* graph = (struct Graph1*)malloc(sizeof(struct Graph1));
            graph->V = v;
            graph->E = e;
            graph->edges = (struct Edge*)malloc(e * sizeof(struct Edge));
            printf("간선 정보 입력 (src dest weight):\n");
            for (int i = 0; i < e; ++i) { scanf_s("%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph->edges[i].weight); }
            kruskal_sort(graph);
            int choose = infoDraw2();
            switch (choose) {
            case 20:
                system("cls");
                _getch();
            case 21:
                break;
            }
            break;
        }
        case 4: {
            Graph graph;
            int vertices, edges;
            printf("Enter the number of vertices: ");
            scanf_s("%d", &vertices);
            initGraph(&graph, vertices);
            printf("Enter the number of edges: ");
            scanf_s("%d", &edges);
            printf("Enter the edges (src dest):\n");
            for (int i = 0; i < edges; ++i) {
                int src, dest;
                scanf_s("%d %d", &src, &dest);
                addEdge3(&graph, src, dest);
            }
            printf("Topological Sort: ");
            topological_sort(&graph);
            int choose = infoDraw2();
            switch (choose) {
            case 20:
                system("cls");
                _getch();
            case 21:
                break;
            }
            break;
        }
        case 5: {
            Point start = { 0, 0 };
            Point goal = { 4, 4 };
            aStar(start, goal);
            int choose = infoDraw2();
            switch (choose) {
            case 20:
                system("cls");
                _getch();
            case 21:
                break;
            }
            break;
        }
        case 6: {
            solveNQueens();
            int choose = infoDraw2();
            switch (choose) {
            case 20:
                system("cls");
                _getch();
            case 21:
                break;
            }
            break;
        }
        case 7: {
            srand(time(NULL));
            Individual population[POPULATION_SIZE];
            initializePopulation(population);
            for (int generation = 0; generation < MAX_GENERATIONS; ++generation) {
                calculateFitness(population);
                printf("Generation %d - Best Fitness: %d\n", generation, population[0].fitness);

                Individual parent1 = population[0];
                Individual parent2 = population[1];

                Individual child1, child2;
                crossover(parent1, parent2, &child1, &child2);
                mutate(&child1);
                mutate(&child2);

                population[POPULATION_SIZE - 2] = child1;
                population[POPULATION_SIZE - 1] = child2;

                qsort(population, POPULATION_SIZE, sizeof(Individual), compareFitness);
            }
            printf("Final Population:\n");
            printPopulation(population);
            int choose = infoDraw2();
            switch (choose) {
            case 20:
                system("cls");
                _getch();
            case 21:
                break;
            }
            break;
        }
        case 8: exit = 0;
        }
        system("cls");
    }
    return 0;
}