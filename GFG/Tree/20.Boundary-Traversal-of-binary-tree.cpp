// Boundary Traversal of binary tree

class Solution {
public:

    void leftside(Node* root, vector<int>& ans) {
        if(!root) return;
        while(root->left || root->right) {
            ans.push_back(root->data);
            if(root->left) root = root->left;
            else root = root->right;
        }
    }
    
    void bottom(Node* root, vector<int>& ans) {
        if(!root) return;
        if(!root->left && !root->right) ans.push_back(root->data);
        bottom(root->left,ans);
        bottom(root->right,ans);
    }
    
    void rightside(Node* root, vector<int>& ans) {
        if(!root) return;
        vector<int> temp;
        while(root->left || root->right) {
            temp.push_back(root->data);
            if(root->right) root = root->right;
            else root = root->left;
        }
        reverse(temp.begin(),temp.end());
        ans.insert(ans.end(),temp.begin(),temp.end());
    }

    vector <int> boundary(Node *root) {
        //Your code here
        if(!root->left && !root->right) return {root->data};
        vector<int> ans;
        ans.push_back(root->data);
        leftside(root->left,ans);
        bottom(root,ans);
        rightside(root->right,ans);
        return ans;
    }
};
