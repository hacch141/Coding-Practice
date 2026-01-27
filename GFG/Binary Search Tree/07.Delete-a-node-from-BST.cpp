// Delete a node from BST

class Solution {

    // Function to delete a node from BST.
    public Node deleteNode(Node root, int X) {
        Node parent = null;
        Node curr = root;

        while (curr != null && curr.data != X) {
            parent = curr;
            if (X < curr.data)
                curr = curr.left;
            else
                curr = curr.right;
        }

        if (curr == null) return root;
        Node newNode = helperDel(curr);
        if (parent == null) return newNode;

        if (parent.left == curr) parent.left = newNode;
        else parent.right = newNode;

        return root;
    }

    // Handles 0, 1, or 2 children
    private Node helperDel(Node curr) {
        if (curr.left == null) return curr.right;
        if (curr.right == null) return curr.left;

        // Both children exist
        Node leftSub = curr.left;
        Node rightSub = curr.right;

        // Find rightmost node of left subtree
        Node temp = leftSub;
        while (temp.right != null) {
            temp = temp.right;
        }

        // Attach right subtree
        temp.right = rightSub;

        return leftSub;
    }
}

// ========================================================

void find(Node* root, int& X, Node*& parent, Node*& curr) {
    if(!root) return;
    
    if(X == root -> data) {
        curr = root;
        return;
    }
    
    while(root) {
        if(X < root -> data) {
            if(root -> left && root -> left -> data == X) {
                parent = root;
                curr = root -> left;
                break;
            }
            else {
                root = root -> left;
            }
        }
        else if(X > root -> data) {
            if(root -> right && root -> right -> data == X) {
                parent = root;
                curr = root -> right;
                break;
            }
            else {
                root = root -> right;
            }
        }
    }
}

Node* helperDel(Node* curr) {
    Node* leftC = curr -> left;
    Node* rightC = curr -> right;
    if(!leftC) return rightC;
    if(!rightC) return leftC;
    
    Node* temp = leftC;
    while(temp -> right) {
        temp = temp -> right;
    }
    temp -> right = rightC;
    return leftC;
}

// Function to delete a node from BST.
Node *deleteNode(Node *root, int X) {
    // your code goes here
    Node* parent = new Node(-1);
    Node* curr = new Node(-1);

    find(root,X,parent,curr);
    if(curr -> data == -1) return root;
    
    Node* newN = helperDel(curr);
    if(parent -> data == -1) return newN;
    
    if(parent -> left == curr) parent -> left = newN;
    if(parent -> right == curr) parent -> right = newN;
    
    return root;
}

// T : O(LogN)
// S : O(LogN)
