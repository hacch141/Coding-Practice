// Burning Tree

class Solution {
    Map<TreeNode,TreeNode> parent;
    TreeNode startNode;

    public void getParent(TreeNode root, int start) {
        if (root == null) return;
        if (root.val == start) {
            startNode = root;
        }
        if (root.left != null) {
            parent.put(root.left, root);
            getParent(root.left, start);
        }
        if (root.right != null) {
            parent.put(root.right, root);
            getParent(root.right, start);
        }
    }

    public int amountOfTime(TreeNode root, int start) {
        parent = new HashMap<>();
        getParent(root, start);

        int ans = 0;
        Set<TreeNode> vis = new HashSet<>();

        Queue<TreeNode> q = new LinkedList<>();
        q.add(startNode);
        vis.add(startNode);

        while (!q.isEmpty()) {
            int sz = q.size();
            while (sz-- > 0) {
                TreeNode curr = q.poll();
                if (curr.left != null && !vis.contains(curr.left)) {
                    vis.add(curr.left);
                    q.add(curr.left);
                }
                if (curr.right != null && !vis.contains(curr.right)) {
                    vis.add(curr.right);
                    q.add(curr.right);
                }
                if (parent.containsKey(curr) && !vis.contains(parent.get(curr))) {
                    TreeNode par = parent.get(curr);
                    vis.add(par);
                    q.add(par);
                }
            }
            ans++;
        }

        return ans - 1;
    }
}

// =======================================================

class Solution {
  public:
  
    void find_parent(Node* root, unordered_map<Node*,Node*>& parent) {
        if(!root) return;
        parent[root->left] = root;
        parent[root->right] = root;
        find_parent(root->left,parent);
        find_parent(root->right,parent);
    }
    
    Node* find_target(Node* root, int& target) {
        if(!root) return NULL;
        if(root->data == target) return root;
        Node* l = find_target(root->left,target);
        Node* r = find_target(root->right,target);
        if(l) return l;
        return r;
    }
  
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*> parent;
        find_parent(root,parent);
        
        Node* tar = find_target(root,target);
        unordered_map<Node*,bool> vis;
        
        queue<Node*> q;
        q.push(tar);
        vis[tar] = true;
        int t = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                Node* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left]) {
                    vis[curr->left] = true;
                    q.push(curr->left);
                }
                if(curr->right && !vis[curr->right]) {
                    vis[curr->right] = true;
                    q.push(curr->right);
                }
                if(parent[curr] && !vis[parent[curr]]) {
                    vis[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }
            t++;
        }
        return t-1;
    }
};
