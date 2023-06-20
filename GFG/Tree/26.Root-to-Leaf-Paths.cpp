// Root to Leaf Paths

// STRIVER
bool getPath(node* root, vector<int>& arr, int x) {
  if (!root) return false;
  arr.push_back(root -> data);
  if (root -> data == x) return true;
  bool l = getPath(root -> left, arr, x);
  bool r = getPath(root -> right, arr, x);
  if (l || r) return true;
  arr.pop_back();
  return false;
}

// me
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
