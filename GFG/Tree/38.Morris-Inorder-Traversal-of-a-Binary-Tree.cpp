// Morris Inorder Traversal of a Binary Tree

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        Node* curr = root;
        while(curr) {
            if(!curr->left) {
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
                    curr = curr -> left;
                }
                else {
                    prev -> right = NULL;
                    ans.push_back(curr -> data);
                    curr = curr -> right;
                }
            }
        }
        return ans;
    }
};

// T : O(N)
// S : O(1)
