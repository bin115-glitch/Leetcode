#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void dfs(int** grid, int gridSize, int* gridColSize, int i, int j) {
    if (i < 0 || i >= gridSize || j < 0 || j >= *gridColSize || grid[i][j] != 1) {
        return;
    }

    grid[i][j] = 2;  
    for (int d = 0; d < 4; d++) {
        int ni = i + directions[d][0];
        int nj = j + directions[d][1];
        dfs(grid, gridSize, gridColSize, ni, nj);
    }
}

int shortestBridge(int** grid, int gridSize, int* gridColSize) {
    int found = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 1) {
                dfs(grid, gridSize, gridColSize, i, j);
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    int distance = 0;
    // Queue for BFS
    int queue[MAX * MAX][2];  // Each element is a pair (i, j)
    int front = 0, rear = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 2) {
                queue[rear][0] = i;  // row index
                queue[rear][1] = j;  // column index
                rear++;
            }
        }
    }
    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            int x = queue[front][0];
            int y = queue[front][1];
            front++;
            for (int d = 0; d < 4; d++) {
                int ni = x + directions[d][0];
                int nj = y + directions[d][1];
                if (ni >= 0 && ni < gridSize && nj >= 0 && nj < *gridColSize) {
                    if (grid[ni][nj] == 1) { 
                        return distance;
                    }
                    if (grid[ni][nj] == 0) {  
                        grid[ni][nj] = 2;
                        queue[rear][0] = ni; 
                        queue[rear][1] = nj;
                        rear++;
                    }
                }
            }
        }
        distance++;  
    }

    return -1;
}