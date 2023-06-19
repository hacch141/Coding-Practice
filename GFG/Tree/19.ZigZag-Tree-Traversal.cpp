// ZigZag Tree Traversal

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root) {
    	// Code here
    	queue<Node*> q;
    	q.push(root);
    	vector<int> ans;
    	bool rev = false;
    	while(!q.empty()) {
    	    int n = q.size();
    	    vector<int> v;
    	    for(int i=0; i<n; i++) {
    	        Node* curr = q.front();
    	        q.pop();
    	        v.push_back(curr->data);
    	        if(curr->left) q.push(curr->left);
    	        if(curr->right) q.push(curr->right);
    	    }
    	    if(rev) reverse(v.begin(),v.end());
    	    ans.insert(ans.end(),v.begin(),v.end());
    	    rev = !rev;
    	}
    	return ans;
    }
};

// T : O(N)
// S : O(N)
