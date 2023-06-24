// Construct Tree from Inorder & Preorder

class Solution{
    public:
    Node* build(int in[], int is, int ie, int pre[], int ps, int pe, map<int,queue<int>>& inmp) {
        if(is>ie || ps>pe) return NULL;
        
        Node* root = new Node(pre[ps]);
        int inRoot = inmp[pre[ps]].front();
        inmp[pre[ps]].pop();
        int numsLeft = inRoot - is;
        
        root->left = build(in,is,inRoot-1,pre,ps+1,ps+numsLeft,inmp);
        root->right = build(in,inRoot+1,ie,pre,ps+numsLeft+1,pe,inmp);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        map<int,queue<int>> inmp;
        for(int i=0; i<n; i++) {
            inmp[in[i]].push(i);
        }
        return build(in,0,n-1,pre,0,n-1,inmp);
    }
};
