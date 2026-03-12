class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> mp;

        for(string s : strs){
            string key = s;
            sort(key.begin(), key.end()); // sắp xếp chữ

            mp[key].push_back(s); // nhóm
        }

        vector<vector<string>> result;
        for(auto &p : mp){
            result.push_back(p.second);
        }

        return result;
    }  
};