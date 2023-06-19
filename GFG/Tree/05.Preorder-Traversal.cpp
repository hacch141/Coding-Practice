// Preorder Traversal

void helper(Node* root, vector<int> &ans) {
    if(root) {
        ans.push_back(root->data);
        helper(root->left,ans);
        helper(root->right,ans);   
    }
}

//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root) {
  // Your code here
  vector<int> ans;
  helper(root,ans);
  return ans;
}

// T : O(N)
// S : O(N)
