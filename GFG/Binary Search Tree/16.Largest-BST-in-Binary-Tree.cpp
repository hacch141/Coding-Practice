// Largest BST in Binary Tree

class NodeValue {
    public:
    int minVal, maxVal, maxSize;
    NodeValue(int minVal, int maxVal, int maxSize) {
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->maxSize = maxSize;
    }
};

NodeValue solve(TreeNode* root) {
    if(!root) {
        return NodeValue(INT_MAX,INT_MIN,0);
    }

    auto l = solve(root->left);
    auto r = solve(root->right);

    if(l.maxVal < root->data && root->data < r.minVal) {
        return NodeValue(min(l.minVal,root->data) , max(r.maxVal,root->data) , l.maxSize + r.maxSize + 1);
    }
    return NodeValue(INT_MIN , INT_MAX , max(l.maxSize,r.maxSize));
}

int largestBST(TreeNode * root){
    // Write your code here.
    return solve(root).maxSize;
}
// T : O(N)
// S : O(N)
