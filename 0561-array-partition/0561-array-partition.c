int arrayPairSum(int* nums, int numsSize) {
    
    int count[20001] = {0}; // từ -10000 → 10000
    for(int i = 0; i < numsSize; i++){
        count[nums[i] + 10000]++;
    }
    int sum = 0;
    int take = 1;
    for(int i = 0; i < 20001; i++){
        while(count[i] > 0){
            if(take){
                sum += (i - 10000);
            }
            take = !take; 
            count[i]--;
        }
    }

    return sum;
}