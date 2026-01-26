// Top View of Binary Tree

// Java
class Solution {
    public ArrayList<Integer> topView(Node root) {
        ArrayList<Integer> ans = new ArrayList<>();
        if (root == null) return ans;

        TreeMap<Integer, Integer> map = new TreeMap<>();
        Queue<Pair> queue = new LinkedList<>();
        queue.offer(new Pair(root, 0));

        while (!queue.isEmpty()) {
            Pair p = queue.poll();
            Node curr = p.node;
            int vertical = p.vertical;

            // first node at this vertical level
            map.putIfAbsent(vertical, curr.data);

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
