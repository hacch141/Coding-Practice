// Bottom View of Binary Tree

// Java
class Solution {
    public ArrayList<Integer> bottomView(Node root) {
        ArrayList<Integer> ans = new ArrayList<>();
        if (root == null) return ans;

        // Map<vertical, nodeValue>
        TreeMap<Integer, Integer> map = new TreeMap<>();

        // Queue of Pair(node, vertical)
        Queue<Pair> queue = new LinkedList<>();
        queue.offer(new Pair(root, 0));

        while (!queue.isEmpty()) {
            Pair p = queue.poll();
            Node curr = p.node;
            int vertical = p.vertical;

            // overwrite to keep bottom-most node
            map.put(vertical, curr.data);

            if (curr.left != null)
                queue.offer(new Pair(curr.left, vertical - 1));

            if (curr.right != null)
                queue.offer(new Pair(curr.right, vertical + 1));
        }

        // Extract result from left to right
        for (int val : map.values()) {
            ans.add(val);
        }

        return ans;
    }
}


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
