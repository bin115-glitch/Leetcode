class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       vector<int> newArr =nums;
       for (int i = 0; i< nums.size(); i++){
            newArr[i] = newArr[i] * newArr[i];
       } 
       sort(newArr.begin(), newArr.end());
       return newArr;
    }
};