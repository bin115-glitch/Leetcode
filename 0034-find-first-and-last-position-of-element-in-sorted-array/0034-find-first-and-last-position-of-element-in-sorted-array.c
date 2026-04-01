/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
   int left = 0;
   int right = numsSize -1;
    int firts = -1, last = -1;
    while(left<=right){
       int mid = left + (right - left)/2;
       if(nums[mid] == target){
            firts = mid;
            right = mid -1;
       }
       else if(nums[mid] < target){
            left = mid +1;
       }
       else{
        right = mid -1;
       }
    }
    left = 0;
    right = numsSize -1;
    while(left<=right){
        int mid = left + (right - left)/2;
        if(nums[mid] == target){
            last = mid;
            left = mid +1;
        }
        else if(nums[mid] < target){
            left = mid +1;
        }
        else{
            right = mid - 1;
        }
    }
    result[0] = firts;
    result[1] = last;
    return result;
}