// 653. Two Sum IV - Input is a BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void getVec(TreeNode* root, vector<int> &vec) {
        if(root == NULL) {
            return;
        }
        getVec(root->left,vec);
        vec.push_back(root->val);
        getVec(root->right,vec);
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) {
            return false;
        }
        vector<int> vec;
        getVec(root,vec);
        
        int low = 0;
        int high = vec.size()-1;
        while(low<high) {
            if(vec[low]+vec[high] == k) {
                return true;
            }
            else if (vec[low]+vec[high] < k){
                low++;
            }
            else {
                high--;
            }
        }
        return false;
    }
};
