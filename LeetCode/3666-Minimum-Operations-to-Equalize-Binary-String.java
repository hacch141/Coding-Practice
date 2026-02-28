// 3666. Minimum Operations to Equalize Binary String

// TLE (n * k)
class Solution {
    public int minOperations(String s, int k) {
        int n = s.length(), cnt0 = 0;

        for (char ch : s.toCharArray()) {
            if (ch == '0') cnt0++;
        }

        Queue<Integer> q = new LinkedList<>();
        int[] operations = new int[n + 1];
        Arrays.fill(operations, -1);

        q.add(cnt0);
        operations[cnt0] = 0;


        // flip f zeros and (k - f) ones
        // f <= cnt0
        // k - f <= n - cnt0 -> f >= k + cnt0 - n
        // max(0, k + cnt0 - n) <= f <= min(k, cnt0)

        while (!q.isEmpty()) {
            int currZ = q.poll();

            int mnF = Math.max(0, k + currZ - n);
            int mxF = Math.min(k, currZ);

            for (int f = mnF; f <= mxF; f++) {

                int newZ = currZ - f + (k - f);

                if (operations[newZ] == -1) {
                    operations[newZ] = operations[currZ] + 1;
                    q.add(newZ);
                }

                if (newZ == 0) {
                    return operations[0];
                }
            }
        }

        return -1;
    }
}

// using TreeSet and iterate only once to target
class Solution {
    public int minOperations(String s, int k) {
        int n = s.length(), cnt0 = 0;

        List<TreeSet<Integer>> nodeSets = new ArrayList<>();
        nodeSets.add(new TreeSet<>());
        nodeSets.add(new TreeSet<>());

        for (int i = 0; i <= n; i++) {
            nodeSets.get(i % 2).add(i);
            if (i < n && s.charAt(i) == '0') cnt0++;
        }

        if (cnt0 == 0) return 0;

        Queue<Integer> q = new LinkedList<>();
        int[] operations = new int[n + 1];
        Arrays.fill(operations, -1);

        q.add(cnt0);
        operations[cnt0] = 0;
        nodeSets.get(cnt0 % 2).remove(cnt0);


        // flip f zeros and (k - f) ones
        // f <= cnt0
        // k - f <= n - cnt0 -> f >= k + cnt0 - n
        // max(0, k + cnt0 - n) <= f <= min(k, cnt0)

        while (!q.isEmpty()) {
            int currZ = q.poll();

            int mnF = Math.max(0, k + currZ - n);
            int mxF = Math.min(k, currZ);

            int lNode = currZ + k - 2*mxF;
            int rNode = currZ + k - 2*mnF;

            TreeSet<Integer> nodeSet = nodeSets.get(lNode % 2);

            for (Integer newZ = nodeSet.ceiling(lNode); newZ != null && newZ <= rNode; newZ=nodeSet.ceiling(newZ)) {

                if (operations[newZ] == -1) {
                    operations[newZ] = operations[currZ] + 1;
                    q.add(newZ);
                    nodeSet.remove(newZ);
                }

                if (newZ == 0) {
                    return operations[0];
                }
            }
        }

        return -1;
    }
}
