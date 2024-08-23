// 3248. Snake in Matrix

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0, j = 0;
        for(auto s : commands) {
            if(s == "RIGHT") {
                j++;
            }
            else if(s == "LEFT") {
                j--;
            }
            else if(s == "UP") {
                i--;
            }
            else {
                i++;
            }
        }
        return (n * i) + j;
    }
};
