// Insert a node in a BST

// Function to insert a node in a BST.
Node* insert(Node* root, int Key) {
    // Your code here
    if(!root) return new Node(Key);
    
    Node* curr = root;
    while(true) {
        if(Key == curr -> data) {
            break;
        }
        else if(Key > curr -> data) {
            if(curr -> right) {
                curr = curr -> right;
            }
            else {
                curr -> right = new Node(Key);
                break;
            }
        }
        else {
            if(curr -> left) {
                curr = curr -> left;
            }
            else {
                curr -> left = new Node(Key);
                break;
            }
        }
    }
    return root;
}

// T : O(LogN)
// S : O(1)
