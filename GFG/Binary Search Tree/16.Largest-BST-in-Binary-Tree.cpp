// Largest BST in Binary Tree

class NodeValue {
    int minVal;
    int maxVal;
    int maxSize;

    NodeValue(int minVal, int maxVal, int maxSize) {
        this.minVal = minVal;
        this.maxVal = maxVal;
        this.maxSize = maxSize;
    }
}

class Solution {

    private NodeValue solve(TreeNode root) {
        // Base case: empty tree is a valid BST of size 0
        if (root == null) {
            return new NodeValue(Integer.MAX_VALUE, Integer.MIN_VALUE, 0);
        }

        NodeValue left = solve(root.left);
        NodeValue right = solve(root.right);

        // Check BST property
        if (left.maxVal < root.data && root.data < right.minVal) {
            return new NodeValue(
                Math.min(left.minVal, root.data),
                Math.max(right.maxVal, root.data),
                left.maxSize + right.maxSize + 1
            );
        }

        // Not a BST → propagate largest BST size found so far
        return new NodeValue(
            Integer.MIN_VALUE,
            Integer.MAX_VALUE,
            Math.max(left.maxSize, right.maxSize)
        );
    }

    // Function to find the size of the largest BST in a binary tree
    public int largestBST(TreeNode root) {
        return solve(root).maxSize;
    }
}

// ==========================================================================

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
