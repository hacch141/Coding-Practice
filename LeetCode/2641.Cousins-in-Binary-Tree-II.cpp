// 2641. Cousins in Binary Tree II

// DFS + BFS
class Solution {
public:
    void find_lvl_sum(TreeNode* root, int lvl, unordered_map<int,int>& lvl_sum) {
        if(!root) return;
        lvl_sum[lvl] += root->val;
        find_lvl_sum(root->left, lvl + 1, lvl_sum);
        find_lvl_sum(root->right, lvl + 1, lvl_sum);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int,int> lvl_sum;
        find_lvl_sum(root, 0, lvl_sum);

        queue<TreeNode*> q;
        q.push(root);

        root->val = 0;
        int lvl = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                TreeNode* curr = q.front();
                q.pop();

                int l = curr->left ? curr->left->val : 0;
                int r = curr->right ? curr->right->val : 0;

                if(curr->left) {
                    curr->left->val = lvl_sum[lvl + 1] - l - r;
                    q.push(curr->left);
                }
                if(curr->right) {
                    curr->right->val = lvl_sum[lvl + 1] - l - r;
                    q.push(curr->right);
                }
            }
            lvl++;
        }

        return root;
    }
};


// BFS
class Solution {
public:
    vector<int> findLvlSum(TreeNode* root) {
        vector<int> lvlsum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            int sum = 0;
            for(int i=0; i<n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                sum += curr->val;
            }
            lvlsum.push_back(sum);
        }
        return lvlsum;
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> lvlsum = findLvlSum(root);
        queue<TreeNode*> q;

        q.push(root);
        root->val = 0;

        int lvl = 1;
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();

                int c1=0, c2=0;
                if(curr->left) {
                    c1 = curr->left->val;
                    q.push(curr->left);
                }
                if(curr->right) {
                    c2 = curr->right->val;
                    q.push(curr->right);
                }

                if(curr->left) curr->left->val = lvlsum[lvl] - c1 - c2;
                if(curr->right) curr->right->val = lvlsum[lvl] - c1 - c2;
            }
            lvl++;
        }

        return root;
    }
};
