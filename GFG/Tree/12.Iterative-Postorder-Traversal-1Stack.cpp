// Postorder Traversal

// ONE STACK
vector <int> postOrder(Node* root) {
  // Your code here
  vector<int> ans;
  stack<Node*> st;
  Node* curr = root;
  while(curr || !st.empty()) {
      if(curr) {
          st.push(curr);
          curr = curr->left;
      }
      else {
          Node* temp = st.top()->right;
          if(temp==NULL) {
              temp = st.top();
              st.pop();
              ans.push_back(temp->data);
              while(!st.empty() && temp==st.top()->right) {
                  temp = st.top();
                  st.pop();
                  ans.push_back(temp->data);
              }
          }
          else {
              curr = temp;
          }
      }
  }
  return ans;
}

// T : O(N)
// S : O(N)
