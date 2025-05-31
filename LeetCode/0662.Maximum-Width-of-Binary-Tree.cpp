// 662. Maximum Width of Binary Tree

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 1;

        queue<pair<TreeNode*,long long>> q;
        q.push({root, 0});

        while(!q.empty()) {
            int sz = q.size();
            long long first = q.front().second, last = q.back().second;

            while(sz--) {
                auto it = q.front();
                q.pop();

                TreeNode* curr = it.first;
                long long ind = it.second - first;

                if(curr->left) q.push({curr->left, (2 * ind) + 1});
                if(curr->right) q.push({curr->right, (2 * ind) + 2});
            }
            ans = max(ans, (int)(last - first + 1));
        }

        return ans;
    }
};
