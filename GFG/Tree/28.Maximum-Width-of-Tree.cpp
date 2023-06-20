// Maximum Width of Tree

// STRIVER
int widthOfBinaryTree(node * root) {
  if (!root) return 0;
  int ans = 0;
  queue <pair<node*,int>> q;
  q.push({root,0});
    
  while (!q.empty()) {
    int size = q.size();
    int curMin = q.front().second;
    int leftMost, rightMost;
    for (int i=0; i<size; i++) {
      int cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
      node* temp = q.front().first;
      q.pop();
      if (i == 0) leftMost = cur_id;
      if (i == size - 1) rightMost = cur_id;
      if (temp->left) q.push({temp->left,cur_id * 2 + 1});
      if (temp -> right) q.push({temp -> right,cur_id * 2 + 2});
    }
    ans = max(ans, rightMost - leftMost + 1);
  }
  return ans;
}

class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {
        // Your code here
        queue<Node*> q;
        q.push(root);
        int res = 0;
        while(!q.empty()) {
            int cnt = q.size();
            res = max(res,cnt);
            for(int i=0; i<cnt; i++) {
                Node* curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return res;
    }
};

// T : O(N)
// S : O(H)
