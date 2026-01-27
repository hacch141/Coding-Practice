// Predecessor and Successor

class Solution {

    // pre[0] and suc[0] will store predecessor and successor
    public void findPreSuc(Node root, Node[] pre, Node[] suc, int key) {
        Node curr = root;
        while (curr != null) {
            if (curr.key == key) {
                // Predecessor: max value in left subtree
                if (curr.left != null) {
                    Node temp = curr.left;
                    while (temp.right != null)
                        temp = temp.right;
                    pre[0] = temp;
                }
                // Successor: min value in right subtree
                if (curr.right != null) {
                    Node temp = curr.right;
                    while (temp.left != null)
                        temp = temp.left;
                    suc[0] = temp;
                }
                return;
            }
            else if (key > curr.key) {
                pre[0] = curr;        // possible predecessor
                curr = curr.right;
            }
            else {
                suc[0] = curr;        // possible successor
                curr = curr.left;
            }
        }
    }
}

// =============================================================

class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        Node* curr = root;
        while(curr) {
            if(key == curr->key) {
                if(curr->left) {
                    Node* temp = curr->left;
                    while(temp->right) temp = temp->right;
                    pre = temp;
                }
                if(curr->right) {
                    Node* temp = curr->right;
                    while(temp->left) temp = temp->left;
                    suc = temp;
                }
                return;
            }
            else if(key > curr->key) {
                pre = curr;
                curr = curr->right;
            }
            else {
                suc = curr;
                curr = curr->left;
            }
        }
    }
};

// T : O(LogN)
// S : O(1)
