// 2360. Longest Cycle in a Graph

class Solution {
public:

    void dfs(int start, vector<int>& vis, map<int,int>& prevIdx, vector<vector<int>>& adj, int cnt, int& ans) {
        vis[start] = 1;
        prevIdx[start] = cnt;

        for(auto i : adj[start]) {
            if(!vis[i]) {
                dfs(i, vis, prevIdx, adj, cnt+1, ans);
            }
            else if(prevIdx.count(i)){
                ans = max(ans,cnt-prevIdx[i]+1);
            }
        }
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++) {
            if(edges[i]!=-1) {
                adj[i].push_back(edges[i]);
            }
        }

        int ans = -1;
        int cnt = 0;

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                cnt = 0;
                map<int,int> prevIdx;
                dfs(i,vis,prevIdx,adj,cnt,ans);
            }
        }

        return ans;
    }
};
