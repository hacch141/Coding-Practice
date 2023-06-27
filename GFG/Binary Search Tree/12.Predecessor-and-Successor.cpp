// Predecessor and Successor

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
