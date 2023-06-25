// Inorder Traversal

class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        stack<Node*> st;
        Node* curr = root;
        vector<int> ans;
        
        while(curr || !st.empty()) {
            while(curr) {
                st.push(curr);
                curr = curr -> left;
            }
            curr = st.top();
            st.pop();
            ans.push_back(curr -> data);             
            curr = curr -> right;
        }
        return ans;
    }
};
// T : O(N)
// S : O(N)

// ===============================================

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        stack<Node*> st;
        Node* curr = root;
        while(true) {
            if(curr) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                if(st.empty()) break;
                curr = st.top();
                st.pop();
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
        return ans;
    }
};

// T : O(N)
// S : O(N)
