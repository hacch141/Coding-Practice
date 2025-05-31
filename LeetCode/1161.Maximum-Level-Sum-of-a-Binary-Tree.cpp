// 1161. Maximum Level Sum of a Binary Tree

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans = -1, mx_sum = INT_MIN, lvl = 0;
        while(!q.empty()) {
            int sz = q.size(), sum = 0;
            while(sz--) {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            lvl++;

            if(sum > mx_sum) {
                mx_sum = sum;
                ans = lvl;
            }
        }

        return ans;
    }
};

// DFS
//Approach-2 (Using DFS - T.C : O(n))
class Solution {
public:
    
    map<int, int> mp;
    
    void DFS(TreeNode* root, int currLevel) {
        if(!root) return;
        mp[currLevel] += root->val;
        DFS(root->left, currLevel+1);
        DFS(root->right, currLevel+1);
    }
    
    int maxLevelSum(TreeNode* root) {
        mp.clear();
        DFS(root, 1);
        int maxSum = INT_MIN;
        int result = 0;
        for(auto &it : mp) {
            int level = it.first;
            int sum   = it.second;
            if(sum > maxSum) {
                maxSum = sum;
                result = level;
            }
        }
        return result;
    }
};
