// Fixing Two nodes of a BST

class Solution {

    private Node prev;
    private Node first;
    private Node middle;
    private Node last;

    private void inorder(Node root) {
        if (root == null) return;

        inorder(root.left);

        if (prev != null && prev.data > root.data) {
            if (first == null) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;

        inorder(root.right);
    }

    // Function to correct a BST where two nodes are swapped
    public void correctBST(Node root) {
        first = middle = last = prev = null;

        inorder(root);

        if (first != null && last != null) {
            // Non-adjacent swap
            int temp = first.data;
            first.data = last.data;
            last.data = temp;
        } else if (first != null && middle != null) {
            // Adjacent swap
            int temp = first.data;
            first.data = middle.data;
            middle.data = temp;
        }
    }
}

// ========================================================================

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
