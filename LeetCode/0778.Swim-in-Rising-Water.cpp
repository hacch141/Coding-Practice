// 778. Swim in Rising Water

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});

        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, -1, 0, +1};

        int ans = INT_MIN;
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int r = it.second.first;
            int c = it.second.second;
            int t = it.first;
            ans = max(ans,t);

            if(vis[r][c]) {
                continue;
            }

            vis[r][c] = 1;

            if(r==n-1 && c==m-1) {
                return ans;
            }

            for(int del=0; del<4; del++) {
                int newr = r + delRow[del];
                int newc = c + delCol[del];
                if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc]) {
                    int newt = grid[newr][newc];
                    pq.push({newt,{newr,newc}});
                }
            }
        }

        return -1;
    }
};
