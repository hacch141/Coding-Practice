// 863. All Nodes Distance K in Binary Tree

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public Map<TreeNode, TreeNode> parent;

    public void getParent(TreeNode root) {
        if (root == null) return;
        if (root.left != null) {
            parent.put(root.left, root);
            getParent(root.left);
        }
        if (root.right != null) {
            parent.put(root.right, root);
            getParent(root.right);
        }
    }

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {

        parent = new HashMap<>();
        getParent(root);

        List<Integer> ans = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();

        Set<TreeNode> vis = new HashSet<>();
        q.add(target);
        vis.add(target);
        int lvl = 0;

        while (!q.isEmpty()) {
            if (lvl == k) {
                while (!q.isEmpty()) {
                    ans.add(q.poll().val);
                }
            }
            int sz = q.size();
            while (sz-- > 0) {
                TreeNode curr = q.poll();
                if (curr.left != null && !vis.contains(curr.left)) {
                    vis.add(curr.left);
                    q.add(curr.left);
                }
                if (curr.right != null && !vis.contains(curr.right)) {
                    vis.add(curr.right);
                    q.add(curr.right);
                }
                if (parent.get(curr) != null && !vis.contains(parent.get(curr))) {
                    TreeNode par = parent.get(curr);
                    vis.add(par);
                    q.add(par);
                }
            }
            lvl++;
        }

        return ans;
    }
}
