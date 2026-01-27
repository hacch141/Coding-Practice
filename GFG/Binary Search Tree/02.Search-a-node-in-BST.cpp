// Search a node in BST

class Solution {
    boolean search(Node root, int x) {
        Node curr = root;

        while (curr != null) {
            if (x == curr.data) {
                return true;
            } else if (x < curr.data) {
                curr = curr.left;
            } else {
                curr = curr.right;
            }
        }
        return false;
    }
}

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
