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


// STRIVER
class bstIterator{
        stack<Node*> st;
        int reverse=1;
    private:
        void pushall(Node* root){
            while(root){
                st.push(root);
                if(reverse) root=root->right;
                else root=root->left;
            }
        }
    public:
        bstIterator(Node* root, int isreverse){
            reverse=isreverse;
            pushall(root);
        }
        int next(){
            Node* node=st.top();
            st.pop();
            if(!reverse) pushall(node->right);
            else pushall(node->left);
            return node->data;
        }
};

class Solution{
  public:
    int isPairPresent(struct Node *root, int k){
        if(!root) return false;
        bstIterator next(root,false);
        bstIterator before(root,true);
        int i=next.next();
        int j=before.next();
        while(i<j){
            if(i+j==k) return true;
            if(i+j<k) i=next.next();
            else j=before.next();
        }
        return false;
    }
};
