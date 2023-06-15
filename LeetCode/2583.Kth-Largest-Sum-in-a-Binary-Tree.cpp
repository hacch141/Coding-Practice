// 2583. Kth Largest Sum in a Binary Tree

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        while(!q.empty()) {
            int n = q.size();
            long long int sum = 0;
            for(int i=0; i<n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            pq.push(sum);
            if(pq.size()>k) pq.pop();
        }
        if(pq.size() != k) return -1;
        return pq.top();
    }
};
