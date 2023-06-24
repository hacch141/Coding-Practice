// Serialize and Deserialize a Binary Tree

class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        if(!root) return {-1};
        
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if(!curr) ans.push_back(-1);
            else {
                ans.push_back(curr -> data);
                q.push(curr -> left);
                q.push(curr -> right);
            }
        }
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       int n = A.size();
       if(A[0] == -1) return NULL;
      
       Node* root = new Node(A[0]);
       queue<Node*> q;
       q.push(root);
       int i = 1;
       
       while(i<n && !q.empty()) {
           Node* curr = q.front();
           q.pop();
           if(i<n && A[i] != -1) {
               curr -> left = new Node(A[i]);
               q.push(curr -> left);
           }
           i++;
           if(i<n && A[i] != -1) {
               curr -> right = new Node(A[i]);
               q.push(curr -> right);
           }
           i++;
       }
       return root;
    }
};

// T : O(N)
// S : O(N)
