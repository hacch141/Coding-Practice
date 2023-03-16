// 106. Construct Binary Tree from Inorder and Postorder Traversal

class Solution {
public:

    TreeNode* helper(vector<int>& inorder, int start, int end, vector<int>& postorder, int rootIdx) {
        if(start>end || rootIdx<0) return NULL;
        TreeNode* curr = new TreeNode(postorder[rootIdx]);
        int inIdx = 0;
        int num;
        for(int i=start; i<=end; i++) {
            if(inorder[i]==curr->val) {
                inIdx = i;
                num = end-i;
                break;
            }
        }
        curr->left = helper(inorder,start,inIdx-1,postorder,rootIdx-num-1);
        curr->right = helper(inorder,inIdx+1,end,postorder,rootIdx-1);
        return curr;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size()-1, postorder, inorder.size()-1);
    }
};
