// Postorder Traversal

// TWO STACKS
vector <int> postOrder(Node* root) {
  // Your code here
  vector<int> ans;
  stack<Node*> st1;
  stack<Node*> st2;
  st1.push(root);
  while(!st1.empty()) {
      Node* curr = st1.top();
      st1.pop();
      st2.push(curr);
      if(curr->left) st1.push(curr->left);
      if(curr->right) st1.push(curr->right);
  }
  while(!st2.empty()) {
      Node* curr = st2.top();
      st2.pop();
      ans.push_back(curr->data);
  }
  return ans;
}

// T : O(N)
// S : O(N)

// BY USING REV 
vector<int> postorderTraversal(TreeNode* root)
{
    // Write your code here	
    vector<int> ans;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();
        ans.push_back(curr->val);
        if(curr->left) st.push(curr->left);
        if(curr->right) st.push(curr->right);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
// T : O(N)
// S : O(N)
