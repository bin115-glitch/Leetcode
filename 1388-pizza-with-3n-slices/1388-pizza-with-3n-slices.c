#define MAX 500
int max(int a, int b){
    return a > b ? a :b;
}
int slove(int* arr, int size, int k){
    int dp[MAX][MAX] = {0};
    for(int i=1; i<= size;i++){
        for(int j=1;j<=k;j++){
            dp[i][j] = dp[i-1][j];
            int val = arr[i-1];
            if(i>=2){
                dp[i][j] = max(dp[i][j], dp[i-2][j-1] + val);
            }
            else if(i ==1){
                dp[i][j] = max(dp[i][j], val);
            }
        }
    } 
    return dp[size][k];
}
int maxSizeSlices(int* slices, int slicesSize) {
    int k = slicesSize /3;
    int res1 = slove(slices +1 , slicesSize-1,k);
    int res2 = slove(slices, slicesSize -1,k);
    return max(res1, res2);
}