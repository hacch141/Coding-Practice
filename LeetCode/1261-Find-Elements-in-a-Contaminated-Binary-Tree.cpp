// 1261. Find Elements in a Contaminated Binary Tree

// DFS
class FindElements {
public:
    set<int> st;

    void rec(TreeNode* root) {
        if(!root) return;
        if(root->left) {
            root->left->val = 2 * root->val + 1;
            st.insert(2 * root->val + 1);
            rec(root->left);
        }
        if(root->right) {
            root->right->val = 2 * root->val + 2;
            st.insert(2 * root->val + 2);
            rec(root->right);
        }
    }

    FindElements(TreeNode* root) {
        root->val = 0;
        st.insert(0);
        rec(root);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};

// BFS
class FindElements {
public:
    unordered_set<int> st;
    void bfs(TreeNode* root, int x) {
        queue<TreeNode*> que;
        root->val = x;
        que.push(root);

        while(!que.empty()) {
            TreeNode* temp = que.front();
            que.pop();

            st.insert(temp->val);

            if(temp->left) {
                temp->left->val = 2*temp->val + 1;
                que.push(temp->left);
            }

            if(temp->right) {
                temp->right->val = 2*temp->val + 2;
                que.push(temp->right);
            }
            
        }
    }
    FindElements(TreeNode* root) {
        st.clear();
        bfs(root, 0);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};
