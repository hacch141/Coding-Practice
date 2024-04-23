// 310. Minimum Height Trees

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> tree(n);
        for(auto i : edges) {
            tree[i[0]].push_back(i[1]);
            tree[i[1]].push_back(i[0]);
        }

        vector<int> prev(n), dist(n, 0);
        function<void(int,int)> dfs = [&](int u, int p) {
            prev[u] = p;
            for(auto v : tree[u]) {
                if(v == p) continue;
                dist[v] = 1 + dist[u];
                dfs(v, u);
            }
        };
        
        dfs(0, 0);
        int x = max_element(dist.begin(), dist.end()) - dist.begin();
        dist[x] = 0;
        
        dfs(x, x);
        int y = max_element(dist.begin(), dist.end()) - dist.begin();

        vector<int> path;
        path.push_back(y);
        while(y != prev[y]) {
            y = prev[y];
            path.push_back(y);
        }

        int len = path.size();
        vector<int> ans;
        if((len % 2 == 1)) ans = { path[len / 2] };
        else ans = { path[len / 2] , path[len / 2 - 1] };
        return ans;
    }
};


// ======================================================================================

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if(n<=0)
            return res;
        
        if(n==1){
            res.push_back(0);
            return res;
        }
        
        vector<int> deg(n,0);
        vector<vector<int>> gr(n);
        
        for(auto e : edges){
            deg[e[0]]++;
            deg[e[1]]++;
            
            gr[e[0]].push_back(e[1]);
            gr[e[1]].push_back(e[0]);
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(deg[i]==1)
                q.push(i);
        }
        
        while(n>2){
            int sz = q.size();
            n -= sz;
            
            while(sz>0){
                int el = q.front();
                q.pop();
                
                for(auto ne : gr[el]){
                    deg[ne]--;
                    if(deg[ne]==1){
                        q.push(ne);
                    }
                }
                sz--;
            }
        }
        
        while(!q.empty()){
            int el= q.front();
            q.pop();
            
            res.push_back(el);
        }
        
        return res;
    }
};

