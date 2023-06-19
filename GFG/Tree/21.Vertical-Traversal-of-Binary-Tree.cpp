// Vertical Traversal of Binary Tree

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map<int,vector<int>> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* curr = it.first;
            int verticle = it.second;
            mp[verticle].push_back(curr->data);
            if(curr->left) q.push({curr->left,verticle-1});
            if(curr->right) q.push({curr->right,verticle+1});
        }
        
        vector<int> ans;
        for(auto i : mp) {
            ans.insert(ans.end(),i.second.begin(),i.second.end());
        }
        
        return ans;
    }
};
// T : O(NlogN)
// S : O(N)


// STRIVER
vector<vector<int>> findVertical(node* root) {
  map<int,map<int,multiset<int>>> nodes;
  queue<pair<node*,pair<int,int>>> todo;
  todo.push({root,{0,0}}); //initial vertical and level
  while (!todo.empty()) {
    auto p = todo.front();
    todo.pop();
    node * temp = p.first;

    //x -> vertical , y->level
    int x = p.second.first, y = p.second.second;
    nodes[x][y].insert(temp -> data); //inserting to multiset

    if (temp -> left) todo.push({temp -> left,{x - 1,y + 1}});
    if (temp -> right) todo.push({temp -> right,{x + 1,y + 1}});
  }
  vector<vector<int>> ans;
  for (auto p: nodes) {
    vector<int> col;
    for (auto q : p.second) {
      col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
  }
  return ans;
}
