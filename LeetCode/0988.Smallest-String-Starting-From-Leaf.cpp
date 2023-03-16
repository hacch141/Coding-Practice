// 988. Smallest String Starting From Leaf

class Solution {
public:

    string helper(TreeNode* root, string str) {
        if(root) {
            char curr = root->val + 'a';
            str += curr;
            if(!root->left && !root->right) {
                reverse(str.begin(),str.end());
                return str;
            }

            if(root->left && root->right) {
                return min(helper(root->left,str),helper(root->right,str));
            }
            else if(root->left) return helper(root->left,str);
            else if(root->right) return helper(root->right,str);
        }
        return "";
    }

    string smallestFromLeaf(TreeNode* root) {
        return helper(root,"");
    }
};
