// 2641. Cousins in Binary Tree II

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
        root->val = 0;
        if(root->left) {
            q.push(root->left);
            root->left->val = 0;
        }
        if(root->right) {
            q.push(root->right);
            root->right->val = 0;
        }
        int lvl = 2;
        while(!q.empty()) {
            int n = q.size();
            for(int i=0; i<n; i++) {
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
                if(curr->left) curr->left->val = lvlsum[lvl]-c1-c2;
                if(curr->right) curr->right->val = lvlsum[lvl]-c1-c2;
            }
            lvl++;
        }
        return root;
    }
};
