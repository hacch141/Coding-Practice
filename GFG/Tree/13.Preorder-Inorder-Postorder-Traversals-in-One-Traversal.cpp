// Preorder Inorder Postorder Traversals in One Traversal

void allTraversal(node* root, vector<int>& pre, vector<int>& in , vector<int>& post) {
  stack <pair<node*,int>> st;
  st.push({root,1});
  while (!st.empty()) {
    auto it = st.top();
    st.pop();
    if (it.second == 1) {
      pre.push_back(it.first->data);
      it.second++;
      st.push(it);
      if (it.first->left) st.push({it.first->left,1});
    }
    else if (it.second == 2) {
      in .push_back(it.first->data);
      it.second++;
      st.push(it);
      if (it.first->right) st.push({it.first->right,1});
    }
    // don't push it back again 
    else {
      post.push_back(it.first->data);
    }
  }
}
