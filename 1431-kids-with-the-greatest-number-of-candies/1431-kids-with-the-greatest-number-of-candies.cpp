class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candies = candies[0];
        for(int i = 0; i < candies.size();i++){
            if(candies[i] > max_candies){
                max_candies = candies[i];
            }
        }
        vector<bool> resultf;
        for(int i = 0 ; i< candies.size(); i++){
            if((candies[i] + extraCandies) >= max_candies){
                resultf.push_back(true);
            }
            else{
                resultf.push_back(false);
            }
        }
        return resultf;
    }
};