// Ceil in BST

// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    // Your code here
    int ceil = -1;
    Node* curr = root;
    while(curr) {
        if(input == curr -> data) {
            return input;
        }
        else if(input < curr -> data) {
            ceil = curr -> data;
            curr = curr -> left;
        }
        else {
            curr = curr -> right;
        }
    }
    return ceil;
}

// T : O(LogN)
// S : O(1)
