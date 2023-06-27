// Find a pair with given target in BST

class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    
    void push_left(Node* root, stack<Node*>& st) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }
    
    void push_right(Node* root, stack<Node*>& st) {
        while(root) {
            st.push(root);
            root = root->right;
        }
    }
    
    int isPairPresent(struct Node *root, int target)
    {
    //add code here.
        stack<Node*> st1;
        stack<Node*> st2;
        push_left(root,st1);
        push_right(root,st2);
        
        while(!st1.empty() && !st2.empty()) {
            Node* curr1 = st1.top();
            Node* curr2 = st2.top();
            int sum = curr1->data + curr2->data;
            if(curr1 == curr2) {
                return false;
            }
            else if(sum == target) {
                return true;
            }
            else if(sum < target) {
                st1.pop();
                push_left(curr1->right,st1);
            }
            else {
                st2.pop();
                push_right(curr2->left,st2);
            }
        }
        return false;
    }
};

// T : O(M+N)
// S : O(Height)
