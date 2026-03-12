class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0;
        int y=0;
        for(char a : moves){
            if(a == 'U') y++;
            else if(a == 'D') y--;
            else if(a == 'R') x++;
            else if(a == 'L') x--;
        }
        return x==0 && y==0;
    }
};