// 105. Construct Binary Tree from Preorder and Inorder Traversal

class Solution {
    int ptr = 0;

    public TreeNode build(int l, int r, int[] inorder, int[] preorder) {
        if (l > r || ptr >= preorder.length) return null;

        TreeNode root = new TreeNode(preorder[ptr++]);
        int ind = -1;
        for (int i = l; i <= r; i++) {
            if (inorder[i] == root.val) {
                ind = i;
                break;
            }
        }

        if (ind == -1) return root;

        root.left = build(l, ind - 1, inorder, preorder);
        root.right = build(ind + 1, r, inorder, preorder);

        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int n = preorder.length;
        return build(0, n - 1, inorder, preorder);
    }
}
