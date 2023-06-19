// Top View of Binary Tree

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        queue<pair<Node*,int>> q;
        q.push({root,0});
        map<int,int> mp;
        
        while(!q.empty()) {
            Node* curr = q.front().first;
            int verticle = q.front().second;
            q.pop();
            if(mp.find(verticle) == mp.end()) mp[verticle] = curr->data;
            if(curr->left) q.push({curr->left,verticle-1});
            if(curr->right) q.push({curr->right,verticle+1});
        }
        
        vector<int> ans;
        for(auto i : mp) ans.push_back(i.second);
        return ans;
    }
};

// T : O(NlogN)
// S : O(N)
