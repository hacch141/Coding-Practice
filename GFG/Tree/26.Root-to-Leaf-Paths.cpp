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
// Java
class Solution {
    private void solve(Node root, List<Integer> curr, List<List<Integer>> ans) {
        curr.add(root.data);
        // Leaf node
        if (root.left == null && root.right == null) {
            ans.add(new ArrayList<>(curr)); // IMPORTANT: copy
            curr.remove(curr.size() - 1);
            return;
        }
        if (root.left != null) solve(root.left, curr, ans);
        if (root.right != null) solve(root.right, curr, ans);
        // Backtrack
        curr.remove(curr.size() - 1);
    }

    public List<List<Integer>> Paths(Node root) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();
        if (root == null) return ans;
        solve(root, curr, ans);
        return ans;
    }
}


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
