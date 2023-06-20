// Root to Leaf Paths

void solve(Node* root, vector<int>& curr, vector<vector<int>>& ans) {
    curr.push_back(root->data);
    if(!root->left && !root->right) {
        ans.push_back(curr);
        curr.pop_back();
        return;
    }
    if(root->left) solve(root->left,curr,ans);
    if(root->right) solve(root->right,curr,ans);
    curr.pop_back();
    return;
}
 
vector<vector<int>> Paths(Node* root)
{
    // Code here
    vector<vector<int>> ans;
    vector<int> curr;
    solve(root,curr,ans);
    return ans;
}

// T : O(N)
// S : O(H)
