// 988. Smallest String Starting From Leaf

class Solution {
public:
    void dfs(TreeNode* root, string& curr, string& ans) {
        if(!root) return;

        curr.push_back(root->val + 'a');
        if(!root->left && !root->right) {
            string tmp = curr;
            reverse(tmp.begin(), tmp.end());
            if(ans == "-1") ans = tmp;
            else ans = min (ans, tmp);
        }

        dfs(root->left, curr, ans);
        dfs(root->right, curr, ans);
        curr.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {
        string curr = "", ans = "-1";
        dfs(root, curr, ans);
        return ans;
    }
};
