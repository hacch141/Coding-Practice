// 2192. All Ancestors of a Node in a Directed Acyclic Graph

class Solution {
public:

    vector<int> merge(vector<int> a, vector<int> b) {
        int n1 = a.size(), n2 = b.size();
        vector<int> v;
        int p1 = 0, p2 = 0;
        while(p1 < n1 && p2 < n2) {
            if(a[p1] == b[p2]) {
                v.push_back(a[p1]);
                p1++;
                p2++;
            }
            else if(a[p1] < b[p2]) {
                v.push_back(a[p1]);
                p1++;
            }
            else {
                v.push_back(b[p2]);
                p2++;
            }
        }

        while(p1 < n1) {
            v.push_back(a[p1]);
            p1++;
        }

        while(p2 < n2) {
            v.push_back(b[p2]);
            p2++;
        }

        return v;
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        for(auto i : edges) {
            indegree[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        vector<vector<int>> ans(n);
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(auto v : adj[u]) {

                ans[v] = merge(ans[v], ans[u]);
                ans[v] = merge(ans[v], {u});
                
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }

        return ans;
    }
};
