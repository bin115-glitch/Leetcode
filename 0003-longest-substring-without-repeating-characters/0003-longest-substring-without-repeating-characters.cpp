class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> seen(256, false);
        int l = 0;
        int max_len = 0;
        for (int r = 0; r < s.size(); r ++){
            while(seen[s[r]] == true){
                seen[s[l]] = false;
                l++;
            }
            seen[s[r]] = true;
            int len = r - l + 1;
            if(len > max_len){
            max_len = len;
        }
        }
        return max_len;
    }
};