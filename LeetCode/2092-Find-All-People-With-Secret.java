// 2092. Find All People With Secret

class Solution {
    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {

        Comparator<int[]> cmp = (a, b) -> {
            return a[2] - b[2];
        };
        Arrays.sort(meetings, cmp);

        boolean[] hasSecret = new boolean[n];
        hasSecret[0] = hasSecret[firstPerson] = true;

        int i = 0, len = meetings.length;
        while (i < len) {
            Map<Integer,List<Integer>> adj = new HashMap<>();
            Set<Integer> involved = new HashSet<>();
            int st = i;
            while (i < len && meetings[i][2] == meetings[st][2]) {
                int u = meetings[i][0], v = meetings[i][1];
                adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
                adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
                if (hasSecret[u]) involved.add(u);
                if (hasSecret[v]) involved.add(v);
                i++;
            }

            Queue<Integer> q = new LinkedList<>(involved);
            Set<Integer> vis = new HashSet<>(involved);

            while (!q.isEmpty()) {
                int sz = q.size();
                while (sz-- > 0) {
                    int u = q.poll();
                    for (int v : adj.get(u)) {
                        if (!vis.contains(v)) {
                            vis.add(v);
                            hasSecret[v] = true;
                            q.add(v);
                        }
                    }
                }
            }

        }

        List<Integer> ans = new ArrayList<>();
        for (i = 0; i < n; i++) {
            if (hasSecret[i] == true) ans.add(i);
        }

        return ans;
    }
}
