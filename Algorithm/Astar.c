#include "Astar.h"

double heuristic(Point a, Point b) {
    return fabs(a.row - b.row) + fabs(a.col - b.col);
}

// ��� ���� �Լ�
Node4* createNode(Point point, double g, double h, Node4* parent) {
    Node4* node = (Node4*)malloc(sizeof(Node4));
    node->point = point;
    node->g = g;
    node->h = h;
    node->f = g + h;
    node->parent = parent;
    return node;
}

// ��� �迭���� �ּ� f ���� ���� ��带 ã�� �Լ�
int findMinF(Node4** openSet, int openSetSize) {
    double minF = openSet[0]->f;
    int minIndex = 0;

    for (int i = 1; i < openSetSize; ++i) {
        if (openSet[i]->f < minF) {
            minF = openSet[i]->f;
            minIndex = i;
        }
    }

    return minIndex;
}

// ��� �迭���� Ư�� ��带 �����ϴ� �Լ�
void removeFromOpenSet(Node4** openSet, int* openSetSize, int index) {
    for (int i = index; i < *openSetSize - 1; ++i) {
        openSet[i] = openSet[i + 1];
    }
    (*openSetSize)--;
}

// ��尡 �迭�� �ִ��� Ȯ���ϴ� �Լ�
bool isInOpenSet(Node4** openSet, int openSetSize, Point point) {
    for (int i = 0; i < openSetSize; ++i) {
        if (openSet[i]->point.row == point.row && openSet[i]->point.col == point.col) {
            return true;
        }
    }
    return false;
}

// ��� ��� �Լ�
void printPath(Node4* endNode) {
    if (endNode != NULL) {
        printPath(endNode->parent);
        printf("(%d, %d) ", endNode->point.row, endNode->point.col);
    }
}

// A* �˰��� �Լ�
void aStar(Point start, Point goal) {
    Node4* startNode = createNode(start, 0.0, heuristic(start, goal), NULL);

    Node4* openSet[ROWS * COLS];
    int openSetSize = 1;
    openSet[0] = startNode;

    Node4* closedSet[ROWS][COLS];
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            closedSet[i][j] = NULL;
        }
    }

    while (openSetSize > 0) {
        int currentIndex = findMinF(openSet, openSetSize);
        Node4* currentNode = openSet[currentIndex];

        if (currentNode->point.row == goal.row && currentNode->point.col == goal.col) {
            printf("Path found: ");
            printPath(currentNode);
            printf("\n");
            return;
        }

        removeFromOpenSet(openSet, &openSetSize, currentIndex);
        closedSet[currentNode->point.row][currentNode->point.col] = currentNode;

        // �̿� ��� ��ȸ
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int newRow = currentNode->point.row + i;
                int newCol = currentNode->point.col + j;

                // ��ȿ�� ��ǥ���� Ȯ��
                if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS) {
                    // ���� ���� ��쿡�� ó��
                    if (!(newRow == 1 && newCol == 2) && !(newRow == 2 && newCol == 2)) {
                        Point neighbor = { newRow, newCol };

                        // �̹� closedSet�� �ִ� ���� ����
                        if (closedSet[newRow][newCol] != NULL) {
                            continue;
                        }

                        double tentativeG = currentNode->g + 1.0; // ����� �׻� 1

                        // �̿��� openSet�� ���ų� �� ���� ������� ���� ������ ���
                        if (!isInOpenSet(openSet, openSetSize, neighbor) || tentativeG < openSet[findMinF(openSet, openSetSize)]->g) {
                            Node4* neighborNode = createNode(neighbor, tentativeG, heuristic(neighbor, goal), currentNode);

                            if (!isInOpenSet(openSet, openSetSize, neighbor)) {
                                openSet[openSetSize++] = neighborNode;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Path not found\n");
}