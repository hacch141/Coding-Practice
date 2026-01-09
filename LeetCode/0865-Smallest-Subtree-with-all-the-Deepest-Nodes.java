// 865. Smallest Subtree with all the Deepest Nodes

class Solution {
    public int getHeight(TreeNode root) {
        if (root == null) return 0;
        int l = getHeight(root.left);
        int r = getHeight(root.right);
        return 1 + Math.max(l, r);
    }

    public TreeNode solve(TreeNode root, int currHeight, int maxHeight) {
        if (root == null) return null;

        if (currHeight == maxHeight) return root;

        TreeNode l = solve(root.left, 1 + currHeight, maxHeight);
        TreeNode r = solve(root.right, 1 + currHeight, maxHeight);

        if (l != null && r != null) return root;
        else if (l != null) return l;
        return r;
    }

    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        int height = getHeight(root);
        return solve(root, 1, height);
    }
}
