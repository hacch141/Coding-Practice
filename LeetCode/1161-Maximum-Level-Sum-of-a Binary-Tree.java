// 1161. Maximum Level Sum of a Binary Tree

class Solution {
    public int maxLevelSum(TreeNode root) {
        int mxSum = Integer.MIN_VALUE;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int currLevel = 1, mxLevel = 1;
        while (!q.isEmpty()) {
            int sz = q.size();
            int currSum = 0;
            while (sz-- > 0) {
                TreeNode currNode = q.poll();
                currSum += currNode.val;
                if (currNode.left != null) q.add(currNode.left);
                if (currNode.right != null) q.add(currNode.right);
            }
            if (currSum > mxSum) {
                mxSum = currSum;
                mxLevel = currLevel;
            }
            currLevel++;
        }
        return mxLevel;
    }
}
