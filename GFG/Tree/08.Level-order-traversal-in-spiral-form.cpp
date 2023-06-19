// Level order traversal in spiral form

//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root) {
    //Your code here
    vector<int> ans;
    if(root == NULL) {
        return {};
    }
    queue<Node*> q;
    stack<int> st;
    bool reverse = true;
    q.push(root);
    
    while(q.empty() == false) {
        int cnt = q.size();
        for(int i=0; i<cnt; i++) {
            Node* curr = q.front();
            q.pop();
            if(reverse) {
                st.push(curr->data);
            }
            else {
                ans.push_back(curr->data);
            }
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        if(reverse) {
            while(st.empty() == false) {
                ans.push_back(st.top());
                st.pop();
            }
        }
        reverse = !reverse;
    }
    return ans;
}



// By using vector
vector<int> findSpiral(Node *root)
{
    //Your code here
    if(!root) return {};
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    bool rev = true;
    while(!q.empty()) {
        int n = q.size();
        vector<int> lvl;
        for(int i=0; i<n; i++) {
            Node* curr = q.front();
            q.pop();
            lvl.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        if(rev) {
            reverse(lvl.begin(),lvl.end());
        }
        rev = !rev;
        ans.insert(ans.end(), lvl.begin(), lvl.end());
    }
    return ans;
}
