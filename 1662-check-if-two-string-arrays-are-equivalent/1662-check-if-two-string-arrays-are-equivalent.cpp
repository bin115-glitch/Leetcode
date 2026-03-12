class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1;
        string s2;
        for (string a : word1){
            s1+=a;
        }
        for (string b : word2){
            s2+=b;
        }
        return s1 == s2;
    }
};