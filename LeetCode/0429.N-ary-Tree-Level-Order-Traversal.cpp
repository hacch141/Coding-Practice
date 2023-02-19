// 429. N-ary Tree Level Order Traversal

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        ans.push_back({root->val});
        vector<int> temp;

        while(!q.empty()) {
            int len = q.size();
            for(int i=0; i<len; i++) {
                Node* curr = q.front();
                q.pop();
                for(auto it : curr->children) {
                    q.push(it);
                    temp.push_back(it->val);
                }
            }
            if(temp.size()>0) ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};
