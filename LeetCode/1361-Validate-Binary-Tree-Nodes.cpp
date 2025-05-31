// 1361. Validate Binary Tree Nodes

// BFS
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1) indegree[leftChild[i]]++;
            if(rightChild[i] != -1) indegree[rightChild[i]]++;
        }
        
        int st = -1;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                if(st == -1) st = i;
                else return false;
            }
            if(indegree[i] > 1) return false;
        }
        if(st == -1) return false;

        vector<bool> vis(n, false);
        vis[st] = true;

        queue<int> q;
        q.push(st);

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int curr = q.front();
                q.pop();
                if(leftChild[curr] != -1 && !vis[leftChild[curr]]) {
                    q.push(leftChild[curr]);
                    vis[leftChild[curr]] = true;
                }
                if(rightChild[curr] != -1 && !vis[rightChild[curr]]) {
                    q.push(rightChild[curr]);
                    vis[rightChild[curr]] = true;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(!vis[i]) return false;
        }

        return true;
    }
};

// DFS
class Solution {
public:

    bool dfs(int u, vector<int>& leftChild, vector<int>& rightChild, vector<bool>& vis) {
        vis[u] = true;
        if(leftChild[u] != -1) {
            if(vis[leftChild[u]] || !dfs(leftChild[u], leftChild, rightChild, vis)) return false;
        }
        if(rightChild[u] != -1) {
            if(vis[rightChild[u]] || !dfs(rightChild[u], leftChild, rightChild, vis)) return false;
        }
        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1) indegree[leftChild[i]]++;
            if(rightChild[i] != -1) indegree[rightChild[i]]++;
        }

        int st = -1;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                if(st == -1) st = i;
                else return false;
            }
        }
        if(st == -1) return false;

        vector<bool> vis(n, false);
        if(!dfs(st, leftChild, rightChild, vis)) return false;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) return false;
        }

        return true;
    }
};

// =====================================================

class DisjointSet {
private:
    vector<int> parent;
    int cmp;
public:
    DisjointSet(int n) {
        cmp = n;
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int find_par(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find_par(parent[u]);
    }

    bool union_by_size(int par, int child) {
        int par_par = find_par(par);
        int par_child = find_par(child);

        if(par_child != child || par_par == child) return false;

        parent[child] = par;
        cmp--;
        return true;
    }

    int get_cmp() {
        return cmp;
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        DisjointSet ds(n);
        for(int i = 0; i < n; i++) {
            if(leftChild[i] >= 0 && !ds.union_by_size(i, leftChild[i])) return false;
            if(rightChild[i] >= 0 && !ds.union_by_size(i, rightChild[i])) return false;
        }
        return ds.get_cmp() == 1;
    }
};
