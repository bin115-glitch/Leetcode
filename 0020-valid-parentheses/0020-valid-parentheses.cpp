class Solution {
public:
    bool isValid(string s) {
        string input;

        for(char a : s){

            if(a == '(' || a == '{' || a == '['){
                input.push_back(a);
            }
            else{

                if(input.empty()){
                    return false;
                }

                char top_back = input.back();
                input.pop_back();

                if(a == '}' && top_back != '{' ||
                   a == ')' && top_back != '(' ||
                   a == ']' && top_back != '['){
                    return false;
                }
            }
        }

        return input.empty();
    }
};