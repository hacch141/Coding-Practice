// Search a node in BST

bool search(Node* root, int x) {
    // Your code here
    Node* curr = root;
    while(curr) {
        if(x == curr -> data) {
            return true;
        }
        else if(x < curr -> data) {
            curr = curr -> left;
        }
        else {
            curr = curr -> right;
        }
    }
    return false;
}

// T : O(LogN)
// S : O(1)
