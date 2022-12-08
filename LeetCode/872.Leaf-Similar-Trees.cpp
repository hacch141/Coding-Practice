// 872. Leaf-Similar Trees

class Solution {
public:

    void getleaves(TreeNode* root, vector<int> &leaves) {
        if(root) {
            if(!root->left && !root->right) {
                leaves.push_back(root->val);
            }
            getleaves(root->left,leaves);
            getleaves(root->right,leaves);
        }
        return;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL || root2==NULL) return false;
        vector<int> leaves1, leaves2;
        getleaves(root1,leaves1);
        getleaves(root2,leaves2);
        if(leaves1.size() != leaves2.size()) return false;
        for(int i=0; i<leaves1.size(); i++) {
            if(leaves1[i] != leaves2[i]) return false;
        }
        return true;
    }
};
