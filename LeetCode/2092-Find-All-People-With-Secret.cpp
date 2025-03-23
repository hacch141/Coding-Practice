// 2092. Find All People With Secret

// bfs
class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2) {
        return v1[2] < v2[2];
    }

    void dfs(int u, unordered_map<int,vector<int>>& adj, unordered_set<int>& vis, unordered_set<int>& has_secret) {
        vis.insert(u);
        has_secret.insert(u);
        for(auto &v : adj[u]) {
            if(!vis.count(v)) {
                dfs(v, adj, vis, has_secret);
            }
        }
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), cmp);
        int ind = 0;

        unordered_set<int> has_secret = {0, firstPerson};
        
        while(ind < meetings.size()) {
            unordered_map<int,vector<int>> adj;
            unordered_set<int> start_from;

            int curr_time = meetings[ind][2];

            while(ind < meetings.size() && meetings[ind][2] == curr_time) {
                int u = meetings[ind][0], v = meetings[ind][1];
                adj[u].push_back(v);
                adj[v].push_back(u);
                if(has_secret.count(u)) start_from.insert(u);
                if(has_secret.count(v)) start_from.insert(v);
                ind++;
            }

            unordered_set<int> vis;
            for(auto &st : start_from) {
                if(!vis.count(st)) {
                    dfs(st, adj, vis, has_secret);
                }
            }
        }

        vector<int> ans;
        for(auto &p : has_secret) ans.push_back(p);

        return ans;
    }
};

// ==============================================================

// Dijkstra
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : meetings) {
            int u = it[0], v = it[1], t = it[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});

        vector<int> time(n, 1e9);
        time[0] = time[firstPerson] = 0;

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int t = curr.first;
            int u = curr.second;
            for(auto it : adj[u]) {
                int v = it.first;
                int next_t = it.second;
                if(next_t >= t && next_t < time[v]) {
                    time[v] = next_t;
                    pq.push({next_t, v});
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(time[i] != 1e9) ans.push_back(i);
        }

        return ans;
    }
};

// ===============================================================

class DisjointSet {
public:
    vector<int> parent,rank;
    DisjointSet(int n) {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    
    int par(int node) {
        return parent[node] = ((node == parent[node]) ? node : par(parent[node]));
    }
    
    void add(int u, int v) {
        int ulp_u = par(u), ulp_v = par(v);
        if(ulp_u != ulp_v) {
            if(rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
            }
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
    }

    void remove(int u) {
        parent[u] = u;
    }
};

class Solution {
public:

    static bool cmp(vector<int>& v1, vector<int>& v2) {
        return v1[2] < v2[2];
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(),meetings.end(),cmp);
        DisjointSet ds(n);
        ds.add(0, firstPerson);

        int ptr = 0, len = meetings.size();
        while(ptr < len) {
            int t = meetings[ptr][2];
            vector<int> ppl;
            while(ptr < len && meetings[ptr][2] == t) {
                int u = meetings[ptr][0];
                int v = meetings[ptr][1];
                ppl.push_back(u);
                ppl.push_back(v);
                ds.add(u , v);
                ptr++;
            }
            for(auto u : ppl) {
                if(ds.par(u) != ds.par(0)) ds.remove(u);
            }
        }

        vector<int> ans;
        ans.push_back(0);
        for(int u = 1; u < n; u++) {
            if(ds.par(u) == ds.par(0)) ans.push_back(u);
        }

        return ans;
    }
};
