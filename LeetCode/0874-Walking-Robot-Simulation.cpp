// 874. Walking Robot Simulation

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<vector<int>> st;
        for(auto i : obstacles) st.insert(i);
        int n = commands.size(), x = 0, y = 0, dir = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            if(commands[i] == -1) {
                dir = (dir + 1) % 4;
            }
            else if(commands[i] == -2) {
                dir = (dir - 1 + 4) % 4;
            }
            else {
                int nx = x, ny = y;
                for(int j = 0; j < commands[i]; j++) {
                    ny += dir == 0;
                    nx += dir == 1;
                    ny -= dir == 2;
                    nx -= dir == 3;
                    if(st.count({nx, ny})) break;
                    x = nx, y = ny;
                }
                ans = max(ans, x * x + y * y);
            }
        }
        return ans;
    }
};
