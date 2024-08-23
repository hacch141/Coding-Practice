// 3238. Find the Number of Winning Players

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> f(n, vector<int>(11, 0));
        int win = 0;
        for(auto it : pick) {
            f[it[0]][it[1]]++;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 11; j++) {
                if(f[i][j] > i) {
                    win++;
                    break;
                }
            }
        }
        return win;
    }
};
