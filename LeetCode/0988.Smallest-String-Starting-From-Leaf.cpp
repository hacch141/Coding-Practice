// 988. Smallest String Starting From Leaf

// DFS
class Solution {
public:
    void dfs(TreeNode* root, string& curr, string& ans) {
        if(!root) return;

        curr.push_back(root->val + 'a');
        if(!root->left && !root->right) {
            string tmp = curr;
            reverse(tmp.begin(), tmp.end());
            if(ans == "-1") ans = tmp;
            else ans = min (ans, tmp);
        }

        dfs(root->left, curr, ans);
        dfs(root->right, curr, ans);
        curr.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {
        string curr = "", ans = "-1";
        dfs(root, curr, ans);
        return ans;
    }
};

// BFS
//Approach-2 (Using BFS)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        queue<pair<TreeNode*, string>> que;
        
        string result = "";
        que.push({root, string(1, root->val + 'a')});
        
        while(!que.empty()) {
            
            auto[node, curr] = que.front();
            que.pop();
            
            if(node->left == NULL && node->right == NULL) {
                if(result == "" || result > curr) {
                    result = curr;
                }
            }
            
            if(node->left) {
                que.push({node->left, char(node->left->val + 'a') + curr});
            }
            
            if(node->right) {
                que.push({node->right, char(node->right->val + 'a') + curr});
            }
            
        }
        
        return result;
    }
};
