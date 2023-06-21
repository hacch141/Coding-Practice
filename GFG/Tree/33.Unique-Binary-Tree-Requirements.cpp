// Unique Binary Tree Requirements

// Each traversal is represented with an integer: preorder - 1, inorder - 2, postorder - 3.
// we need inorder + preorder OR inorder + postorder for construct a unique binary tree
class Solution
{
public:
    bool isPossible(int a,int b)
    {
        //code here
        if(a==b) return false;
        return a+b==3 || a+b==5;
    }
};
