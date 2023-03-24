// 1466. Reorder Routes to Make All Paths Lead to the City Zero

class Solution {
public:

    void bfs(int& cnt, vector<vector<int>>& adj, int& n) {
        queue<int> q;
        q.push(0);
        vector<int> vis(n,0);
        vis[0] = 1;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(auto i : adj[curr]) {
                int next = abs(i);
                if(!vis[next]) {
                    vis[next] = 1;
                    q.push(next);
                    if(i>0) cnt++;
                }
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(auto& i : connections) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(-i[0]);
        }

        int cnt = 0;
        bfs(cnt,adj,n);
        return cnt;
    }
};
