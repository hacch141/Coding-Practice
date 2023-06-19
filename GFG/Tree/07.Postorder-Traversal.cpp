// Postorder Traversal

void helper(Node* root, vector<int> &ans) {
    if(root) {
        helper(root->left,ans);
        helper(root->right,ans);
        ans.push_back(root->data);
    }
}

//Function to return a list containing the postorder traversal of the tree.
vector <int> postOrder(Node* root) {
  // Your code here
  vector<int> ans;
  helper(root,ans);
  return ans;
}

// T : O(N)
// S : O(N)
