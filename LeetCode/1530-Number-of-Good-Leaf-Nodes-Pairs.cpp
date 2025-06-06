// 1530. Number of Good Leaf Nodes Pairs

// DFS
class Solution {
public:
    // map<dist,cnt> from root
    unordered_map<int,int> dfs(TreeNode* root, int& dist, int& ans) {
        unordered_map<int,int> curr, left, right;
        if(!root) return curr;
        if(!root->left && !root->right) {
            curr[0] = 1;
            return curr;
        }

        left = dfs(root->left, dist, ans);
        right = dfs(root->right, dist, ans);

        for(auto l : left) {
            int d1 = l.first + 1;
            int c1 = l.second;
            for(auto r : right) {
                int d2 = r.first + 1;
                int c2 = r.second;
                if(d1 + d2 <= dist) ans += c1 * c2;
            }
        }

        for(auto l : left) curr[l.first + 1] += l.second;
        for(auto r : right) curr[r.first + 1] += r.second;

        return curr;
    }

    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }
};

//Approach-1 (Using Graph and BFS)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:

    void makeGraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>>& adj, 
                    unordered_set<TreeNode*>& st) {

        if(root == NULL) {
            return;
        }

        if(root->left == NULL && root->right == NULL) { //LEAF NODE
            st.insert(root);
        }

        if(prev != NULL) {
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }

        makeGraph(root->left, root, adj, st);
        makeGraph(root->right, root, adj, st);

    }

    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj; //Graph
        unordered_set<TreeNode*> st; //leaf nodes

        makeGraph(root, NULL, adj, st);

        int count = 0; //count of good node pairs

        for(auto &leaf : st) {

            //BFS hit karo and see if you can find another leaf nodes within distance
            queue<TreeNode*> que;
            unordered_set<TreeNode*> visited;
            que.push(leaf);
            visited.insert(leaf);


            for(int level = 0; level <= distance; level++) { //only go till level <= distance
                int size = que.size();
                while(size--) { //level processed
                    TreeNode* curr = que.front();
                    que.pop();

                    if(curr != leaf && st.count(curr)) { 
                        count++;
                    }

                    for(auto &ngbr : adj[curr]) {
                        if(!visited.count(ngbr)) {
                            que.push(ngbr);
                            visited.insert(ngbr);
                        }
                    }
                }
            }
        }
        return count/2;
    }
};
