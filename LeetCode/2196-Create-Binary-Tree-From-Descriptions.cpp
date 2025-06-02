// 2196. Create Binary Tree From Descriptions

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        set<int> childs;

        for(auto it : descriptions) {
            TreeNode* par;
            TreeNode* child;

            if(mp.count(it[0])) par = mp[it[0]];
            else mp[it[0]] = par = new TreeNode(it[0]);

            if(mp.count(it[1])) child = mp[it[1]];
            else mp[it[1]] = child = new TreeNode(it[1]);

            if(it[2]) par->left = child;
            else par->right = child;

            childs.insert(it[1]);
        }

        for(auto it : descriptions) {
            if(!childs.count(it[0])) return mp[it[0]];
        }

        return NULL;
    }
};

// Kind of BFS
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, vector<pair<int,int>>> mp;
        set<int> nodes;
        for(auto i : descriptions) {
            mp[i[0]].push_back({i[1], i[2]});
            nodes.insert(i[1]);
        }

        int par;
        for(auto i : descriptions) {
            if(!nodes.count(i[0])) {
                par = i[0];
                break;
            }
        }

        TreeNode* root = new TreeNode(par);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                TreeNode* curr = q.front();
                q.pop();
                int val = curr->val;
                for(auto i : mp[val]) {
                    int child = i.first;
                    bool isLeft = i.second;
                    if(isLeft) {
                        curr->left = new TreeNode(child);
                        q.push(curr->left);
                    }
                    else {
                        curr->right = new TreeNode(child);
                        q.push(curr->right);
                    }
                }
            }
        }

        return root;
    }
};
