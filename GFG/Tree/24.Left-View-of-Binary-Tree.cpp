// Left View of Binary Tree

// Recursive FOR RIGHT VIEW
void solve(Node* root, vector<int>& ans, int level) {
    if(!root) return;
    if(ans.size()==level) ans.push_back(root->data);
    solve(root->right,ans,level+1);
    solve(root->left,ans,level+1);
}


// Recursive FOR LEFT VIEW
void solve(Node* root, vector<int>& ans, int level) {
    if(!root) return;
    if(ans.size()==level) ans.push_back(root->data);
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root) {
   // Your code here
   vector<int> ans;
   solve(root,ans,0);
   return ans;
}

// T : O(N)
// S : O(H)


// Iterative for RIGHT VIEW
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   queue<Node*> q;
   q.push(root);
   while(!q.empty()) {
       int cnt = q.size();
       for(int i=0; i<cnt; i++) {
           Node* curr = q.front();
           q.pop();
           if(i==cnt-1) ans.push_back(curr->data);
           if(curr->left) q.push(curr->left);
           if(curr->right) q.push(curr->right);
       }
   }
   return ans;
}


// Iterative for LEFT VIEW
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   queue<Node*> q;
   q.push(root);
   while(!q.empty()) {
       int cnt = q.size();
       for(int i=0; i<cnt; i++) {
           Node* curr = q.front();
           q.pop();
           if(i==0) ans.push_back(curr->data);
           if(curr->left) q.push(curr->left);
           if(curr->right) q.push(curr->right);
       }
   }
   return ans;
}
// T : O(N)
// S : O(N)
