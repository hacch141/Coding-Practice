// Alien Dictionary

// BFS
class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        
        for(int i=1; i<N; i++) {
            string s1 = dict[i-1];
            string s2 = dict[i];
            int n1 = s1.size();
            int n2 = s2.size();
            int n = min(n1,n2);
            
            for(int j=0; j<n; j++) {
                if(s1[j] != s2[j]) {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        vector<int> indegree(K,0);
        for(int u=0; u<K; u++) {
            for(auto v : adj[u]) {
                indegree[v]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<K; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        string ans = "";
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ans = ans + char(u + 'a');
            
            for(auto v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return ans;
    }
};

// T : O(N * |S| + K) , where |S| denotes maximum length.
// S : O(K)


// DFS
class Solution{
    
    private:
    void dfs(int u, vector<int> adj[], vector<int>& vis, string& ans) {
        vis[u] = 1;
        
        for(auto v : adj[u]) {
            if(!vis[v]) {
                dfs(v,adj,vis,ans);
            }
        }
        
        ans = ans + char(u + 'a');
    }
    
    
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        
        for(int i=1; i<N; i++) {
            string s1 = dict[i-1];
            string s2 = dict[i];
            int n1 = s1.size();
            int n2 = s2.size();
            int n = min(n1,n2);
            
            for(int j=0; j<n; j++) {
                if(s1[j] != s2[j]) {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        vector<int> vis(K,0);
        string ans = "";
        
        for(int i=0; i<K; i++) {
            if(!vis[i]) {
                dfs(i,adj,vis,ans);
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// T : O(N * |S| + K) , where |S| denotes maximum length.
// S : O(K)
