// Nodes at given distance in binary tree

class Solution {
    public Map<TreeNode, TreeNode> parent;

    public void getParent(TreeNode root) {
        if (root == null) return;
        if (root.left != null) {
            parent.put(root.left, root);
            getParent(root.left);
        }
        if (root.right != null) {
            parent.put(root.right, root);
            getParent(root.right);
        }
    }

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {

        parent = new HashMap<>();
        getParent(root);

        List<Integer> ans = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();

        Set<TreeNode> vis = new HashSet<>();
        q.add(target);
        vis.add(target);
        int lvl = 0;

        while (!q.isEmpty()) {
            if (lvl == k) {
                while (!q.isEmpty()) {
                    ans.add(q.poll().val);
                }
            }
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
                if (parent.get(curr) != null && !vis.contains(parent.get(curr))) {
                    TreeNode par = parent.get(curr);
                    vis.add(par);
                    q.add(par);
                }
            }
            lvl++;
        }

        return ans;
    }
}

// ==========================================================

// ME
class Solution
{
private:

public:

    void find_parents(Node* root, unordered_map<Node*,Node*>& parent) {
        if(!root) return;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        find_parents(root->left,parent);
        find_parents(root->right,parent);
    }
    
    Node* find_target(Node* root, int& target) {
        if(!root) return NULL;
        if(root->data == target) return root;
        Node* l = find_target(root->left,target);
        Node* r = find_target(root->right,target);
        if(l) return l;
        return r;
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
         unordered_map<Node*,Node*> parent;
        find_parents(root,parent);
        
        Node* tar = find_target(root,target);
        unordered_map<Node*,bool> vis;
        vector<int> ans;
        
        queue<pair<Node*,int>> q;
        q.push({tar,0});
        vis[tar] = true;
        while(!q.empty()) {
            Node* curr = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(dist==k) {
                ans.push_back(curr->data);
            }
            else {
                if(curr->left && !vis[curr->left]) {
                    q.push({curr->left,dist+1});
                    vis[curr->left] = true;
                }
                if(curr->right && !vis[curr->right]) {
                    q.push({curr->right,dist+1});
                    vis[curr->right] = true;
                }
                if(parent[curr] && !vis[parent[curr]]) {
                    q.push({parent[curr],dist+1});
                    vis[parent[curr]] = true;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

      // queue<Node*> q;
      //   q.push(tar);
      //   vis[tar] = true;
      //   int lvl = 0;
      //   while(!q.empty()) {
      //       if(lvl++ == k) break;
      //       int size = q.size();
      //       for(int i=0; i<size; i++) {
      //           Node* curr = q.front();
      //           q.pop();
      //           if(curr->left && !vis[curr->left]) {
      //               vis[curr->left] = true;
      //               q.push(curr->left);
      //           }
      //           if(curr->right && !vis[curr->right]) {
      //               vis[curr->right] = true;
      //               q.push(curr->right);
      //           }
      //           if(parent[curr] && !vis[parent[curr]]) {
      //               vis[parent[curr]] = true;
      //               q.push(parent[curr]);
      //           }
      //       }
      //   }
      //   while(!q.empty()) {
      //       ans.push_back(q.front()->data);
      //       q.pop();
      //   }
      //   sort(ans.begin(),ans.end());
      //   return ans;
    }
};


// CHAT
class Solution {
public:
    void find_parents(Node* root, unordered_map<Node*,Node*>& parent) {
        if(!root) return;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        find_parents(root->left,parent);
        find_parents(root->right,parent);
    }

    Node* find_target(Node* root, int& target) {
        if(!root) return NULL;
        if(root->data == target) return root;
        Node* l = find_target(root->left,target);
        Node* r = find_target(root->right,target);
        if(l) return l;
        return r;
    }
    
    void find_nodes_at_distance_k(Node* root, int k, vector<int>& result, unordered_map<Node*, bool>& visited, unordered_map<Node*,Node*>& parent) {
        if (!root || visited[root]) return;
    
        visited[root] = true;
        if (k == 0) {
            result.push_back(root->data);
            return;
        }
    
        find_nodes_at_distance_k(root->left, k - 1, result, visited,parent);
        find_nodes_at_distance_k(root->right, k - 1, result, visited,parent);
        find_nodes_at_distance_k(parent[root], k - 1, result, visited,parent);
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        unordered_map<Node*, Node*> parent;
        find_parents(root, parent);
    
        Node* tar = find_target(root, target);
        unordered_map<Node*, bool> visited;
        vector<int> ans;
    
        find_nodes_at_distance_k(tar, k, ans, visited,parent);
    
        sort(ans.begin(), ans.end());
        return ans;
    }
};
