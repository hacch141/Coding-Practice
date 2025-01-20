// 990. Satisfiability of Equality Equations

class DisjointSet {
private:
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find_par(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find_par(parent[u]);
    }

    void union_by_rank(int u, int v) {
        int par_u = find_par(u);
        int par_v = find_par(v);
        if(par_u == par_v) {
            return;
        }
        else if(rank[par_u] > rank[par_v]) {
            parent[par_v] = par_u;
        }
        else if(rank[par_u] < rank[par_v]) {
            parent[par_u] = par_v;
        }
        else {
            parent[par_v] = par_u;
            rank[par_u]++;
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        
        DisjointSet ds(26);
        for(auto &eq : equations) {
            if(eq[1] == '=') {
                int u = eq[0] - 'a', v = eq[3] - 'a';
                ds.union_by_rank(u, v);
            }
        }

        for(auto &eq : equations) {
            if(eq[1] == '!') {
                int u = eq[0] - 'a', v = eq[3] - 'a';
                if (ds.find_par(u) == ds.find_par(v)) return false;
            }
        }

        return true;
    }
};
