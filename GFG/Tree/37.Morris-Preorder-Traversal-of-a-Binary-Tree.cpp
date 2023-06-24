// Morris Preorder Traversal of a Binary Tree

vector <int> preorder(Node* root)
{
  // Your code here
  vector<int> ans;
  Node* curr = root;
  while(curr) {
      if(!curr -> left) {
          ans.push_back(curr -> data);
          curr = curr -> right;
      }
      else {
          Node* prev = curr -> left;
          while(prev -> right && prev -> right != curr) {
              prev = prev -> right;
          }
          if(!prev -> right) {
              prev -> right = curr;
              ans.push_back(curr -> data);
              curr = curr -> left;
          }
          else {
              prev -> right = NULL;
              curr = curr -> right;
          }
      }
  }
  return ans;
}

// T : O(N)
// S : O(1)
