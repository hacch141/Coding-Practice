// 662. Maximum Width of Binary Tree

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*,int>> dq;
        int ans = 1;
        dq.push_back({root,1});

        while(!dq.empty()) {
            int size = dq.size();
            ans = max(ans,dq.back().second-dq.front().second+1);
            int minus = dq.front().second;
            for(int i=0; i<size; i++) {
                TreeNode* curr = dq.front().first;
                long long idx = dq.front().second;
                dq.pop_front();
                if(curr && curr->left) dq.push_back({curr->left,(2*idx)-1-minus});
                if(curr && curr->right) dq.push_back({curr->right,(2*idx)-minus});
            }
        }

        return ans;
    }
};
