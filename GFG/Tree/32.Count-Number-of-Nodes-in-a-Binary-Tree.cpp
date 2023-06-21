// Count Number of Nodes in a Binary Tree

class Solution {
  public:
  
    int solve(Node* root) {
        if(!root) return 0;
        int lh = left_height(root);
        int rh = right_height(root->right);
        if(lh==rh) return (1<<lh)-1;
        return 1 + solve(root->left) + solve(root->right);
    }
    
    int left_height(Node* root) {
        if(!root) return 0;
        int cnt = 1;
        while(root->left) {
            cnt++;
            root = root->left;
        }
        return cnt;
    }
    
    int right_height(Node* root) {
        if(!root) return 0;
        int cnt = 1;
        while(root->right) {
            cnt++;
            root = root->right;
        }
        return cnt;
    }
  
    int countNodes(Node* root) {
        // Write your code here
        return solve(root);
    }
};

// T : O(LogN*LogN)
// S : O(LogN)
