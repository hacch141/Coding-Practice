// Bottom View of Binary Tree

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*,int>> q;
        q.push({root,0});
        map<int,int> mp;
        
        while(!q.empty()) {
            Node* curr = q.front().first;
            int verticle = q.front().second;
            q.pop();
            mp[verticle] = curr->data;
            if(curr->left) q.push({curr->left,verticle-1});
            if(curr->right) q.push({curr->right,verticle+1});
        }
        
        vector<int> ans;
        for(auto i : mp) {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};

// T : O(NlogN)
// S : O(N)
