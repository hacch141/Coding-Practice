// Paths from root with a specified sum

class Solution {
  public:
    void dfs(Node *root, int curr_sum, int& sum, vector<int>& curr, vector<vector<int>>& ans) {
        if(!root) return;
        curr_sum += root->key;
        curr.push_back(root->key);
        if(curr_sum == sum) ans.push_back(curr);
        dfs(root->left, curr_sum, sum, curr, ans);
        dfs(root->right, curr_sum, sum, curr, ans);
        curr.pop_back();
    }
  
    vector<vector<int>> printPaths(Node *root, int sum) {
        vector<int> curr;
        vector<vector<int>> ans;
        dfs(root, 0, sum, curr, ans);
        return ans;
    }
};

// https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1
