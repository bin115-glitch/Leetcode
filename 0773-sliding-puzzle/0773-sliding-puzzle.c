#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int slidingPuzzle(int** board, int boardSize, int* boardColSize) {
    char target[] = "123450";

    // 🔹 convert board -> string
    char start[7];
    int k = 0;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            start[k++] = board[i][j] + '0';
        }
    }
    start[6] = '\0';

    // 🔹 BFS queue
    char queue[1000][7];
    int front = 0, rear = 0;

    // 🔹 visited
    char visited[1000][7];
    int visitedSize = 0;

    strcpy(queue[rear++], start);
    strcpy(visited[visitedSize++], start);

    int step = 0;

    // 🔥 BFS
    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            char cur[7];
            strcpy(cur, queue[front++]);

            // ✅ check target
            if (strcmp(cur, target) == 0)
                return step;

            // 🔍 tìm vị trí 0
            int zero;
            for (zero = 0; zero < 6; zero++) {
                if (cur[zero] == '0') break;
            }

            // 🔹 convert index -> row, col
            int row = zero / 3;
            int col = zero % 3;

            // 🔹 4 hướng: lên, xuống, trái, phải
            int dr[4] = {-1, 1, 0, 0};
            int dc[4] = {0, 0, -1, 1};

            for (int d = 0; d < 4; d++) {
                int nr = row + dr[d];
                int nc = col + dc[d];

                // ✅ kiểm tra hợp lệ
                if (nr >= 0 && nr < 2 && nc >= 0 && nc < 3) {
                    int nextIdx = nr * 3 + nc;

                    char next[7];
                    strcpy(next, cur);

                    // swap
                    char tmp = next[zero];
                    next[zero] = next[nextIdx];
                    next[nextIdx] = tmp;

                    // 🔍 check visited
                    int seen = 0;
                    for (int v = 0; v < visitedSize; v++) {
                        if (strcmp(visited[v], next) == 0) {
                            seen = 1;
                            break;
                        }
                    }

                    if (!seen) {
                        strcpy(queue[rear++], next);
                        strcpy(visited[visitedSize++], next);
                    }
                }
            }
        }
        step++;
    }

    return -1;
}