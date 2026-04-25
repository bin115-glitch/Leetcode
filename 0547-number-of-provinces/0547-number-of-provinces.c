
void dfs(int** isConnected, int n, int visited[], int city) {
    visited[city] = 1;
    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && visited[i] == 0) {
            dfs(isConnected, n, visited, i);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    int visited[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(isConnected, n, visited, i);
            count++; 
        }
    }

    return count;
}