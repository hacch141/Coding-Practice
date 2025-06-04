// 1367. Linked List in Binary Tree

class Solution {
public:
    bool check(ListNode* head, TreeNode* root) {
        if(!head) return true;
        if(!root) return false;
        if(head->val != root->val) return false;
        return check(head->next, root->left) || check(head->next, root->right);
    }

    bool dfs(ListNode* head, TreeNode* root) {
        if(!root) return false;
        return check(head, root) || dfs(head, root->left) || dfs(head, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, root);
    }
};
