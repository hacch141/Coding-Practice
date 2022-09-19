// Construct Tree from Inorder & Preorder

//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    
    public:
    
    int preIdx = 0;
    Node* InPre(int in[],int pre[], int Is, int Ie) {
        if(Is > Ie) {
            return NULL;
        }
        Node* root = new Node(pre[preIdx++]);
        
        int inIndex;
        for(int i=Is; i<=Ie; i++) {
            if(root->data == in[i]) {
                inIndex = i;
                break;
            }
        }
        root->left = InPre(in, pre, Is, inIndex-1);
        root->right = InPre(in, pre, inIndex+1, Ie);
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        Node* root = InPre(in, pre, 0, n-1);
        return root;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends
