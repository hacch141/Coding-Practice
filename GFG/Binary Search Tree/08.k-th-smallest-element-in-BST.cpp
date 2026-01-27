// k-th smallest element in BST

class Solution {
    // Return the Kth smallest element in the given BST
    public int KthSmallestElement(Node root, int K) {
        Stack<Node> st = new Stack<>();
        Node curr = root;
        int cnt = 0;

        // Inorder traversal
        while (curr != null || !st.isEmpty()) {
            while (curr != null) {
                st.push(curr);
                curr = curr.left;
            }

            curr = st.pop();
            cnt++;

            if (cnt == K)
                return curr.data;

            curr = curr.right;
        }
        return -1;
    }
}

class Solution {
    Node kthLargest(Node root, int[] k) {
        if (root == null) return null;

        Node right = kthLargest(root.right, k);
        if (right != null) return right;

        k[0]--;
        if (k[0] == 0) return root;

        return kthLargest(root.left, k);
    }
}

class Solution {
    Node kthSmallest(Node root, int[] k) {
        if (root == null) return null;

        Node left = kthSmallest(root.left, k);
        if (left != null) return left;

        k[0]--;
        if (k[0] == 0) return root;

        return kthSmallest(root.right, k);
    }
}
// 🧠 Why int[] k?
// Java has no pass-by-reference
// Array simulates int& k

// ================================================================

class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        stack<Node*> st;
        Node* curr = root;
        int cnt = 0;

        // Inorder Traversal and return the Kth element whick is Kth smallest
        while(curr || !st.empty()) {
            while(curr) {
                st.push(curr);
                curr = curr -> left;
            }
            curr = st.top();
            st.pop();
            if(cnt == K-1) return curr -> data;
            cnt++;                
            curr = curr -> right;
        }
        return -1;
    }
};

// T : O(N)
// S : O(1)


node* kthlargest(node* root,int& k)
{
	if(root==NULL) return NULL;
	
	node* right=kthlargest(root->right,k);
	if(right!=NULL) return right;
	k--;
	
	if(k==0) return root;
	
	return kthlargest(root->left,k);
}

node* kthsmallest(node* root,int &k)
{
	if(root==NULL) return NULL;
	
	node* left=kthsmallest(root->left,k);
	if(left!=NULL) return left;
	k--;
	if(k==0) return root;
	
	return kthsmallest(root->right,k);
}
