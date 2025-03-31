// 2192. All Ancestors of a Node in a Directed Acyclic Graph

// Topological
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i); 
        }

        map<int, set<int>> mp;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto &v : adj[u]) {
                mp[v].insert(u);
                for(auto &i : mp[u]) mp[v].insert(i);
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }

        vector<vector<int>> ans(n);
        for(int i = 0; i < n; i++) {
            for(auto &node : mp[i]) ans[i].push_back(node);
        }

        return ans;
    }
};

// topological Code With Mik
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int, vector<int>> adj; //S.C : O(V+E)
        
        vector<int> indegree(n, 0);

        for(vector<int>& vec : edges) { //O(E)
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v); //u --> v
            indegree[v]++;
        }

        //TOPOLOGICAL SORTING
        queue<int> que;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }

        vector<int> topoOrder;
        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            topoOrder.push_back(curr);

            for(int &v : adj[curr]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        vector<unordered_set<int>> vec(n);

        for(int &node : topoOrder) {
            for(int &v : adj[node]) {
                vec[v].insert(node); //adding node ancestor
                vec[v].insert(vec[node].begin(), vec[node].end()); //adding ancestors of node
            }
        }

        for(int i = 0; i < n; i++) {
            result[i] = vector<int>(vec[i].begin(), vec[i].end());
            sort(result[i].begin(), result[i].end());
        }

        return result;
    }
};

// dfs
class Solution {
public:
    void DFS(int ancestor, unordered_map<int, vector<int>>& adj, int currNode, vector<vector<int>>& result) {
        for(int &ngbr : adj[currNode]) {
            if(result[ngbr].empty() || result[ngbr].back() != ancestor) { //to avoid duplicate entry
                result[ngbr].push_back(ancestor);
                DFS(ancestor, adj, ngbr, result);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int, vector<int>> adj;

        for(vector<int>& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v); //u --> v
        }

        for(int i = 0; i < n; i++) {
            int ancestor = i;
            DFS(ancestor, adj, i, result);
        }

        return result;
    }
};

// reverse graph + dfs
class Solution {
public:
    void DFS(int u, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        visited[u] = true;
        for(int &v : adj[u]) {
            if(visited[v] != true) {
                DFS(v, adj, visited);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result;
        unordered_map<int, vector<int>> adj;

        for(vector<int>& vec : edges) { //O(E)
            int u = vec[0];
            int v = vec[1];
            adj[v].push_back(u); //v --> u
        }

        for(int u = 0; u < n; u++) {
            vector<int> ancestors;
            vector<bool> visited(n, false);
            DFS(u, adj, visited);

            for(int i = 0; i < n; i++) {
                if(i == u) continue;
                if(visited[i] == true) {
                    ancestors.push_back(i);
                }
            }

            result.push_back(ancestors);
        }
        return result;
    }
};
