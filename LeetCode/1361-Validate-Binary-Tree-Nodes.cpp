// 1361. Validate Binary Tree Nodes

class Solution {
public:

    bool dfs(int u, int n, vector<int>& leftChild, vector<int>& rightChild, vector<bool>& vis, int& cnt) {
        vis[u] = true;
        cnt++;
        if(leftChild[u] != -1) {
            if(vis[leftChild[u]] || !dfs(leftChild[u], n, leftChild, rightChild, vis, cnt)) return false;
        }
        if(rightChild[u] != -1) {
            if(vis[rightChild[u]] || !dfs(rightChild[u], n, leftChild, rightChild, vis, cnt)) return false;
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
                if(st == -1) {
                    st = i;
                }
                else {
                    return false;
                }
            }
        }

        if(st == -1) return false;

        vector<bool> vis(n, false);
        int cnt = 0;
        if(!dfs(st, n, leftChild, rightChild, vis, cnt)) return false;
        return cnt == n;
    }
};

// =====================================================

class Solution {
public:
    vector<int> parent;
    int components;

    int find(int x) {
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }

    bool Union(int par, int child) {
        int child_ka_parent  = find(child);
    
        //child_ka_parent != child --> Child had already some other parent
        if(child_ka_parent != child)
            return false;
        
        int parent_ka_parent = find(par);
        //parent_ka_parent == child_ka_parent ---> Parallel edge (It means, already they were connected by another edge)
        if (parent_ka_parent == child_ka_parent) {
            return false;
        }
        
        parent[child] = par;
        components--;
        return true;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        components = n;
        parent.resize(n);
        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            if (leftChild[i] >= 0 && !Union(i, leftChild[i])) {
                return false;
            }
            if (rightChild[i] >= 0 && !Union(i, rightChild[i])) {
                return false;
            }
        }
        
        return components == 1;
    }
};
