// 2385. Amount of Time for Binary Tree to Be Infected

class Solution {
public:
    void find_par(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& par, int& start, TreeNode*& st) {
        if(!root) return;
        if(root->val == start) st = root;
        if(root->left) {
            par[root->left] = root;
            find_par(root->left, par, start, st);
        }
        if(root->right) {
            par[root->right] = root;
            find_par(root->right, par, start, st);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> par;
        TreeNode* st;
        find_par(root, par, start, st);

        queue<TreeNode*> q;
        q.push(st);

        set<int> vis;
        vis.insert(start);

        int min = -1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto curr = q.front();
                q.pop();
                if(curr->left && !vis.count(curr->left->val)) {
                    q.push(curr->left);
                    vis.insert(curr->left->val);
                }
                if(curr->right && !vis.count(curr->right->val)) {
                    q.push(curr->right);
                    vis.insert(curr->right->val);
                }
                if(par.count(curr) && !vis.count(par[curr]->val)) {
                    q.push(par[curr]);
                    vis.insert(par[curr]->val);
                }
            }
            min++;
        }

        return min;
    }
};

// DFS
class Solution {
public:
    void find_par(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& par, int& start, TreeNode*& st) {
        if(!root) return;
        if(root->val == start) st = root;

        if(root->left) {
            par[root->left] = root;
            find_par(root->left, par, start, st);
        }
        if(root->right) {
            par[root->right] = root;
            find_par(root->right, par, start, st);
        }
    }

    void dfs(TreeNode* root, int min, unordered_map<TreeNode*,TreeNode*>& par, unordered_set<int>& vis, int& ans) {
        if(!root) return;

        ans = max(ans, min);
        vis.insert(root->val);

        if(root->left && !vis.count(root->left->val)) {
            dfs(root->left, min + 1, par, vis, ans);
        }
        if(root->right && !vis.count(root->right->val)) {
            dfs(root->right, min + 1, par, vis, ans);
        }
        if(par.count(root) && !vis.count(par[root]->val)) {
            dfs(par[root], min + 1, par, vis, ans);
        }

    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> par;
        TreeNode* st;
        find_par(root, par, start, st);

        int ans = 0;
        unordered_set<int> vis;
        dfs(st, 0, par, vis, ans);

        return ans;
    }
};

//Approach-1 (Convert tree to graph)
//T.C : O(n) - visiting all nodes
//S.C : O(n) - storing all nodes in graph
class Solution {
public:
    void convert(TreeNode* current, int parent, unordered_map<int, vector<int>>& adj) {
        if (current == nullptr) {
            return;
        }

        if (parent != -1) {
            adj[current->val].push_back(parent);
        }

        if (current->left != nullptr) {
            adj[current->val].push_back(current->left->val);
        } 
        if (current->right != nullptr) {
            adj[current->val].push_back(current->right->val);
        }
        convert(current->left, current->val, adj);
        convert(current->right, current->val, adj);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        convert(root, -1, adj);

        queue<int> que;
        que.push(start);
        unordered_set<int> visited;
        visited.insert(start);
        int minutes = 0;

        while (!que.empty()) {
            int n = que.size();

            while (n--) {
                int curr = que.front();
                que.pop();

                for (int &ngbr : adj[curr]) {
                    if (visited.find(ngbr) == visited.end()) {
                        que.push(ngbr);
                        visited.insert(ngbr);
                    }
                }
            }
            minutes++;
        }

        return minutes - 1;
    }
};


//Approach-2 (Using DFS - one pass solution)
//T.C : O(n)
//S.C : O(n) - Max depth of recursion call stack
class Solution {
public:
    int result = INT_MIN;

    int solve(TreeNode* root, int start) {
        if(root == NULL) {
            return 0;
        }

        int LH = solve(root->left, start);
        int RH = solve(root->right, start);

        if(root->val == start) {
            result = max(LH, RH);
            return -1;
        } else if(LH >= 0 && RH >= 0) {
            return max(LH, RH) + 1;
        } else {
            int d = abs(LH) + abs(RH);
            result = max(result, d);

            return min(LH, RH) - 1;
        }

        return 0;
    }

    int amountOfTime(TreeNode* root, int start) {
        solve(root, start);

        return result;
    }
};
