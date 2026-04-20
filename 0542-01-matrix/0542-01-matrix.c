#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int r, c;
} Node;

int** updateMatrix(int** mat, int matSize, int* matColSize,
                   int* returnSize, int** returnColumnSizes) {

    int m = matSize;
    int n = matColSize[0];

    *returnSize = m;
    *returnColumnSizes = (int*)malloc(sizeof(int) * m);

    int** dist = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        dist[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }

    // queue
    Node* queue = (Node*)malloc(sizeof(Node) * m * n);
    int front = 0, rear = 0;

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    // init
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                dist[i][j] = 0;
                queue[rear++] = (Node){i, j};
            } else {
                dist[i][j] = INT_MAX;
            }
        }
    }

    // BFS
    while (front < rear) {
        Node cur = queue[front++];

        for (int k = 0; k < 4; k++) {
            int nr = cur.r + dirs[k][0];
            int nc = cur.c + dirs[k][1];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            if (dist[nr][nc] > dist[cur.r][cur.c] + 1) {
                dist[nr][nc] = dist[cur.r][cur.c] + 1;
                queue[rear++] = (Node){nr, nc};
            }
        }
    }

    free(queue);
    return dist;
}