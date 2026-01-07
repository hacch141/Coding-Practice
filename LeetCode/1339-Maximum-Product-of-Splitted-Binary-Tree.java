// 1339. Maximum Product of Splitted Binary Tree

class Solution {
    public long sum, ans;
    public long MOD = (long)1e9 + 7;

    public long getSum(TreeNode root) {
        if (root == null) return 0;
        return (long)root.val + getSum(root.left) + getSum(root.right);
    }

    public long solve(TreeNode root) {
        if (root == null) return 0;
        long currSum = (long)root.val + solve(root.left) + solve(root.right);
        ans = Math.max(ans, currSum * (sum - currSum));
        return currSum;
    }

    public int maxProduct(TreeNode root) {
        ans = 0;
        sum = getSum(root);
        solve(root);
        return (int)(ans % MOD);
    }
}
