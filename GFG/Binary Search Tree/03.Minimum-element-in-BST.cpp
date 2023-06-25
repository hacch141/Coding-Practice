// Minimum element in BST

int minValue(Node* root) {
    // Code here
    Node* curr = root;
    if(!curr) return -1;
    
    while(curr -> left) {
        curr = curr -> left;
    }
    return curr -> data;
}

// T : O(LogN)
// S : O(1)
