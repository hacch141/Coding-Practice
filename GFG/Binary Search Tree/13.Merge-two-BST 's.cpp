// Merge two BST 's

class Solution
{
    public:
    
    void push_left(Node* root, stack<Node*>& st) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }
    
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       stack<Node*> st1;
       stack<Node*> st2;
       push_left(root1,st1);
       push_left(root2,st2);
       
       vector<int> ans;
       while(!st1.empty() && !st2.empty()) {
           Node* curr1 = st1.top();
           Node* curr2 = st2.top();
           if(curr1->data <= curr2->data) {
               st1.pop();
               ans.push_back(curr1->data);
               push_left(curr1->right,st1);
           }
           else {
               st2.pop();
               ans.push_back(curr2->data);
               push_left(curr2->right,st2);
           }
       }
       while(!st1.empty()) {
            Node* curr = st1.top();
            st1.pop();
            ans.push_back(curr->data);
            push_left(curr->right,st1);
       }
       while(!st2.empty()) {
            Node* curr = st2.top();
            st2.pop();
            ans.push_back(curr->data);
            push_left(curr->right,st2);
       }
       
       return ans;
    }
};

// T : O(M+N)
// S : O(Height)
