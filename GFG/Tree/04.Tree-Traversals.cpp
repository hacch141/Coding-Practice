// Tree Traversals

#include <bits/stdc++.h> 
using namespace std;

void inorder(BinaryTreeNode<int> *root, vector<int>& in) {
    if(!root) return;
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

void preorder(BinaryTreeNode<int> *root, vector<int>& pre) {
    if(!root) return;
    pre.push_back(root->data);
    preorder(root->left,pre);
    preorder(root->right,pre);
}

void postorder(BinaryTreeNode<int> *root, vector<int>& post) {
    if(!root) return;
    postorder(root->left,post);
    postorder(root->right,post);
    post.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<int> in,pre,post;
    inorder(root,in);
    preorder(root,pre);
    postorder(root,post);
    return {in,pre,post};
}

// T : O(N)
// S : O(N)
