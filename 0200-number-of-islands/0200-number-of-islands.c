void dfs(int i, int j,int gridSize,  int* gridColSize, char** grid){
     if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize[i] || grid[i][j] == '0') {
        return;  
    } 
    grid[i][j] = '0';
   dfs(i + 1, j, gridSize, gridColSize, grid);
    dfs(i - 1, j, gridSize, gridColSize, grid);
    dfs(i,j +1, gridSize, gridColSize, grid);
    dfs(i,j -1, gridSize, gridColSize, grid);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int num_islands = 0;

    for(int i =0; i< gridSize; i++){
        for(int j=0; j < gridColSize[i]; j++){
            if(grid[i][j] == '1'){
                num_islands++;
                dfs(i,j,gridSize,gridColSize,grid);
            }
        }
    }
    return num_islands;
}