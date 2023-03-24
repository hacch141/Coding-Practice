// 1466. Reorder Routes to Make All Paths Lead to the City Zero

class Solution {
public:

    void bfs(int& cnt, unordered_map<string,int>& mp, vector<vector<int>>& adj, int& n) {
        queue<int> q;
        q.push(0);
        vector<int> vis(n,0);
        vis[0] = 1;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(auto i : adj[curr]) {
                if(!vis[i]) {
                    vis[i] = 1;
                    if(mp.find(to_string(curr)+"#"+to_string(i)) != mp.end()) {
                        cnt++;
                    }
                    q.push(i);
                }
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<string,int> mp;
        vector<vector<int>> adj(n);

        for(auto i : connections) {
            mp[to_string(i[0])+"#"+to_string(i[1])]++;
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        int cnt = 0;
        bfs(cnt,mp,adj,n);
        return cnt;
    }
};
