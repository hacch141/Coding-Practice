// Leaf at same level

    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
        set<int> ans;
        queue<Node*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            level++;
            int cnt = q.size();
            for(int i=0; i<cnt; i++) {
                Node* curr = q.front();
                q.pop();
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
                if(!curr->left && !curr->right) {
                    ans.insert(level);
                }
            }
        }
        return ans.size()==1;
    }
