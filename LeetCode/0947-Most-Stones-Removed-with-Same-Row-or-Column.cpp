// 947. Most Stones Removed with Same Row or Column

class Solution {
public:

    int dfs(int x, int y, vector<vector<int>>& adjX, vector<vector<int>>& adjY, set<vector<int>>& vis) {
        if(vis.count({x, y})) return 0;
        vis.insert({x, y});
        int cnt = 1;
        for(auto i : adjX[y]) {
            cnt += dfs(i, y, adjX, adjY, vis);
        }
        for(auto i : adjY[x]) {
            cnt += dfs(x, i, adjX, adjY, vis);
        }
        return cnt;
    }

    int removeStones(vector<vector<int>>& stones) {
        vector<vector<int>> adjX(10005), adjY(10005);
        int n = stones.size();
        for(int i = 0; i < n; i++) {
            int x = stones[i][0], y = stones[i][1];
            adjX[y].push_back(x);
            adjY[x].push_back(y);
        }

        int ans = 0;
        set<vector<int>> vis;
        for(int i = 0; i < n; i++) {
            if(vis.count(stones[i])) continue;
            ans += dfs(stones[i][0], stones[i][1], adjX, adjY, vis) - 1;
        }

        return ans;
    }
};
