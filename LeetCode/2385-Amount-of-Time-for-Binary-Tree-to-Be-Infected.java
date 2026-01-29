// 2385. Amount of Time for Binary Tree to Be Infected

class Solution {
    Map<TreeNode,TreeNode> parent;
    TreeNode startNode;

    public void getParent(TreeNode root, int start) {
        if (root == null) return;
        if (root.val == start) {
            startNode = root;
        }
        if (root.left != null) {
            parent.put(root.left, root);
            getParent(root.left, start);
        }
        if (root.right != null) {
            parent.put(root.right, root);
            getParent(root.right, start);
        }
    }

    public int amountOfTime(TreeNode root, int start) {
        parent = new HashMap<>();
        getParent(root, start);

        int ans = 0;
        Set<TreeNode> vis = new HashSet<>();

        Queue<TreeNode> q = new LinkedList<>();
        q.add(startNode);
        vis.add(startNode);

        while (!q.isEmpty()) {
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
                if (parent.containsKey(curr) && !vis.contains(parent.get(curr))) {
                    TreeNode par = parent.get(curr);
                    vis.add(par);
                    q.add(par);
                }
            }
            ans++;
        }

        return ans - 1;
    }
}
