// Floor in BST

// Function to search a node in BST.
int floor(Node* root, int x) {
    // Code here
    int floor = -1;
    Node* curr = root;
    
    while(curr) {
        if(x == curr -> data) {
            return x;
        }
        else if(x < curr -> data) {
            curr = curr -> left;
        }
        else {
            floor = curr -> data;
            curr = curr -> right;
        }
    }
    return floor;
}

// T : O(LogN)
// S : O(1)
