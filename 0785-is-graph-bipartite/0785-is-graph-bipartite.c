#include <stdbool.h>

bool dfs(int** graph, int* graphColSize, int* color, int node, int c) {
    color[node] = c;

    for (int i = 0; i < graphColSize[node]; i++) {
        int nei = graph[node][i];

        if (color[nei] == 0) {
            if (!dfs(graph, graphColSize, color, nei, -c)) {
                return false;
            }
        } else if (color[nei] == c) {
            return false;
        }
    }

    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int color[graphSize];

    for (int i = 0; i < graphSize; i++) {
        color[i] = 0;
    }

    for (int i = 0; i < graphSize; i++) {
        if (color[i] == 0) {
            if (!dfs(graph, graphColSize, color, i, 1)) {
                return false;
            }
        }
    }

    return true;
}