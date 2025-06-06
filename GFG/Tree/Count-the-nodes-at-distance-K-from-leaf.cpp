// Count the nodes at distance K from leaf

// DFS
class Solution {
  public:
    void dfs(Node* root, vector<Node*>& path, unordered_set<Node*>& result, int k) {
        if (!root) return;
        path.push_back(root);
        
        if (!root->left && !root->right) {
            int idx = path.size() - k - 1;
            if (idx >= 0) result.insert(path[idx]);
        }

        dfs(root->left, path, result, k);
        dfs(root->right, path, result, k);
        
        path.pop_back();
    }
    
    int printKDistantfromLeaf(Node* root, int k) {
        vector<Node*> path;
        unordered_set<Node*> result;
        dfs(root, path, result, k);
        return result.size();
    }
};

// DFS - 2
class Solution {
    public:
    vector<vector<Node*>> paths;
    void storeRootToLeaf(Node* root, vector<Node*>& temp) {
        if(!root) return;

        temp.push_back(root);
        if(!root->left && !root->right) {
            paths.push_back(temp);
        }
        storeRootToLeaf(root->left, temp);
        storeRootToLeaf(root->right, temp);
        temp.pop_back();
    }
    
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k) {
        paths.clear();
        vector<Node*> temp;
    	storeRootToLeaf(root, temp);
    	unordered_set<Node*> st;
    	
    	for(vector<Node*> &vec : paths) {
    	    int n = vec.size();
    	    if(n - k > 0) {
    	        st.insert(vec[n-k-1]);
    	    }
    	}
    	
    	return st.size();
    }
};


// BFS
class Solution {
  public:
    void find_par(Node* root, unordered_map<Node*,Node*>& par, queue<Node*>& q) {
        if(!root) return;
        if(!root->left && !root->right) q.push(root);

        if(root->left) {
            par[root->left] = root;
            find_par(root->left, par, q);
        }
        if(root->right) {
            par[root->right] = root;
            find_par(root->right, par, q);
        }
    }
  
    // Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k) {
        unordered_map<Node*,Node*> par;
        queue<Node*> q;
        find_par(root, par, q);
        
        int lvl = 0;
        while(!q.empty()) {
            if(lvl == k) break;
            int sz = q.size();
            while(sz--) {
                auto curr = q.front();
                q.pop();
                if(par.count(curr)) q.push(par[curr]);
            }
            lvl++;
        }
        
        set<Node*> st;
        while(!q.empty()) {
            st.insert(q.front());
            q.pop();
        }

        return st.size();
    }
};
