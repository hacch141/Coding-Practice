// Tree from Postorder and Inorder

Node* build(int in[], int is, int ie, int post[], int ps, int pe, map<int,int>& inmp) {
    if(is>ie || ps>pe) return NULL;
    
    Node* root = new Node(post[pe]);
    
    int inRoot = inmp[post[pe]];
    int numsLeft = inRoot-is;
    
    root->left = build(in,is,inRoot-1,post,ps,ps+numsLeft-1,inmp);
    root->right = build(in,inRoot+1,ie,post,ps+numsLeft,pe-1,inmp);
    
    return root;
}

//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    map<int,int> inmp;
    for(int i = 0; i < n; i++) {
        inmp[in[i]] = i;
    }
    return build(in,0,n-1,post,0,n-1,inmp);
}
