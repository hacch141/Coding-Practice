// Fixing Two nodes of a BST

class Solution {
    
  private:
    Node* prev;
    Node* first;
    Node* middle;
    Node* last;
    
  public:
  
    void inorder(Node* root) {
        if(!root) return ;
        
        inorder(root->left);
        if(prev && prev->data > root->data) {
            if(!first) {
                first = prev;
                middle = root;
            }
            else {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
  
    void correctBST( struct Node* root )
    {
        // add code here.
        first = middle = last = prev = NULL;
        inorder(root);
        if(first && last) swap(first->data,last->data);
        else swap(first->data,middle->data);
    }
};

// T : O(N)
// S : O(1)
