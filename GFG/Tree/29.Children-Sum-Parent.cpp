// Children Sum Parent

// STRIVER
void reorder(node * root) {
  if (!root->left && !root->right) return;
  int child = 0;
  if (root->left) child += root -> left->data;
  if (root->right) child += root -> right->data;
  if (child < root->data) {
    if (root->left) root->left->data = root->data;
    else if (root->right) root->right->data = root->data;
  }
  reorder(root->left);
  reorder(root->right);
  int tot = 0;
  if (root->left) tot += root->left->data;
  if (root->right) tot += root->right->data;
  root -> data = tot;
}

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        // Add your code here
        if(root == NULL) return true;
        if(!root->left && !root->right) return true;
        int sum = 0;
        if(root->left) sum += root->left->data;
        if(root->right) sum += root->right->data;
        int l = isSumProperty(root->left);
        int r = isSumProperty(root->right);
        return (sum==root->data) && l && r;
    }
};
