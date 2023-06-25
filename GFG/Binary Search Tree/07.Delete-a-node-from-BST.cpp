// Delete a node from BST

void find(Node* root, int& X, Node* prev, Node*& parent, Node*& curr) {
    if(!root) return;
    
    if(X == root -> data) {
        curr = root;
        parent = prev;
        return;
    }
    else if(X < root -> data) {
        find(root -> left, X, root, parent, curr);
    }
    else {
        find(root -> right, X, root, parent, curr);
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

    find(root,X,new Node(-1),parent,curr);
    if(curr -> data == -1) return root;
    
    Node* newN = helperDel(curr);
    if(parent -> data == -1) return newN;
    
    if(parent -> left == curr) parent -> left = newN;
    if(parent -> right == curr) parent -> right = newN;
    
    return root;
}

// T : O(LogN)
// S : O(LogN)
