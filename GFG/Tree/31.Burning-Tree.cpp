// Burning Tree

class Solution {
  public:
  
    void find_parent(Node* root, unordered_map<Node*,Node*>& parent) {
        if(!root) return;
        parent[root->left] = root;
        parent[root->right] = root;
        find_parent(root->left,parent);
        find_parent(root->right,parent);
    }
    
    Node* find_target(Node* root, int& target) {
        if(!root) return NULL;
        if(root->data == target) return root;
        Node* l = find_target(root->left,target);
        Node* r = find_target(root->right,target);
        if(l) return l;
        return r;
    }
  
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*> parent;
        find_parent(root,parent);
        
        Node* tar = find_target(root,target);
        unordered_map<Node*,bool> vis;
        
        queue<Node*> q;
        q.push(tar);
        vis[tar] = true;
        int t = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                Node* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left]) {
                    vis[curr->left] = true;
                    q.push(curr->left);
                }
                if(curr->right && !vis[curr->right]) {
                    vis[curr->right] = true;
                    q.push(curr->right);
                }
                if(parent[curr] && !vis[parent[curr]]) {
                    vis[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }
            t++;
        }
        return t-1;
    }
};
