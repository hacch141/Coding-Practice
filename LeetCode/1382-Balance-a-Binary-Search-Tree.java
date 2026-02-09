// 1382. Balance a Binary Search Tree

class Solution {
    public void dfs(TreeNode root, List<Integer> inOrder) {
        if (root == null) return;

        dfs(root.left, inOrder);
        inOrder.add(root.val);
        dfs(root.right, inOrder);
    }

    public TreeNode solve(List<Integer> inOrder, int l, int r) {
        if (l > r) return null;

        int m = (r - l) / 2 + l;
        TreeNode root = new TreeNode(inOrder.get(m));
        root.left = solve(inOrder, l, m - 1);
        root.right = solve(inOrder, m + 1, r);

        return root;
    }

    public TreeNode balanceBST(TreeNode root) {
        List<Integer> inOrder = new ArrayList<>();
        dfs(root, inOrder);
        return solve(inOrder, 0, inOrder.size() - 1);
    }
}
