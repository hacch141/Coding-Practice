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

// java
class Pair {
    TreeNode node;
    long index;
    Pair(TreeNode node, long index) {
        this.node = node;
        this.index = index;
    }
}

class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        int ans = 1;
        Queue<Pair> queue = new LinkedList<>();
        queue.offer(new Pair(root, 0L));

        while (!queue.isEmpty()) {
            int size = queue.size();
            long first = queue.peek().index;
            long last = first;   // will be updated

            for (int i = 0; i < size; i++) {
                Pair p = queue.poll();
                TreeNode curr = p.node;
                long idx = p.index - first; // normalize

                last = p.index;

                if (curr.left != null) queue.offer(new Pair(curr.left, 2 * idx + 1));
                if (curr.right != null) queue.offer(new Pair(curr.right, 2 * idx + 2));
            }

            ans = Math.max(ans, (int) (last - first + 1));
        }
        return ans;
    }
}

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 1;

        queue<pair<TreeNode*,long long>> q;
        q.push({root, 0});

        while(!q.empty()) {
            int sz = q.size();
            long long first = q.front().second, last = q.back().second;

            while(sz--) {
                auto it = q.front();
                q.pop();

                TreeNode* curr = it.first;
                long long ind = it.second - first;

                if(curr->left) q.push({curr->left, (2 * ind) + 1});
                if(curr->right) q.push({curr->right, (2 * ind) + 2});
            }
            ans = max(ans, (int)(last - first + 1));
        }

        return ans;
    }
};


// T : O(N)
// S : O(H)
