// Create Binary Tree

Node* createTree(vector<int>&arr){
    // Write your code here.
    int n = arr.size();
    if(n == 0) return NULL;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    for(int i=1; i<n; i++) {
        Node* curr = q.front();
        q.pop();
        curr->left = new Node(arr[i]);
        q.push(curr->left);
        i++;
        if(i<n) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
    }
    return root;
}

// T : O(N)
// S : O(N)
