// Alien Dictionary

import java.util.*;

class Solution {

    public String findOrder(String[] dict, int N, int K) {

        ArrayList<Integer>[] adj = new ArrayList[K];
        for (int i = 0; i < K; i++) {
            adj[i] = new ArrayList<>();
        }

        // Build graph from dictionary
        for (int i = 1; i < N; i++) {
            String s1 = dict[i - 1];
            String s2 = dict[i];

            int len = Math.min(s1.length(), s2.length());

            for (int j = 0; j < len; j++) {
                if (s1.charAt(j) != s2.charAt(j)) {
                    adj[s1.charAt(j) - 'a'].add(s2.charAt(j) - 'a');
                    break;
                }
            }
        }

        // Compute indegree
        int[] indegree = new int[K];
        for (int u = 0; u < K; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        // Kahn's Algorithm
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < K; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }

        StringBuilder ans = new StringBuilder();

        while (!q.isEmpty()) {
            int u = q.poll();
            ans.append((char) (u + 'a'));

            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.offer(v);
                }
            }
        }

        return ans.toString();
    }
}

// ===================================================================

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
