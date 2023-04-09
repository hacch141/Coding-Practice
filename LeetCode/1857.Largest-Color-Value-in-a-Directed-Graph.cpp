// 1857. Largest Color Value in a Directed Graph


// BFS
class Solution {
public:

    int largestPathValue(string colors, vector<vector<int>>& edges) {

        int n = colors.size();
        if(edges.size()==0) return 1;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        
        for(auto i : edges) {
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }

        vector<vector<int>> freq(n, vector<int>(26,0));
        for(int i=0; i<n; i++) {
            freq[i][colors[i]-'a']++;
        }

        int ans = INT_MIN;
        int cnt = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            cnt++;

            for(auto v : adj[u]) {
                for(int i=0; i<26; i++) {
                    freq[v][i] = max(freq[v][i], freq[u][i] + (colors[v]-'a' == i ? 1 : 0));
                    ans = max(ans,freq[v][i]);
                }
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }

        }

        return cnt!=n ? -1 : ans;
    }
};


// =========================================================================================

// DFS but TLE :(
class Solution {
public:

    void dfs(int start, string& colors, vector<int>& vis, vector<int>& currvis, vector<vector<int>>& adj, vector<int>& freq, int& ans) {

        if(currvis[start]) {
            ans = -1;
            return;
        }

        vis[start] = 1;
        currvis[start] = 1;
        freq[colors[start]-'a']++;

        if(adj[start].size()==0) {
            for(int i=0; i<26; i++) {
                if(ans!=-1) ans = max(ans,freq[i]);
            }
        }

        for(auto i : adj[start]) {
            dfs(i,colors,vis,currvis,adj,freq,ans);
        }

        freq[colors[start]-'a']--;
        currvis[start] = 0;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        
        for(auto i : edges) {
            adj[i[0]].push_back(i[1]);
        }

        vector<int> vis(n,0);
        vector<int> currvis(n,0);
        vector<int> freq(26,0);

        int ans = INT_MIN;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(i,colors,vis,currvis,adj,freq,ans);
            }
        }

        return ans;
    }
};
