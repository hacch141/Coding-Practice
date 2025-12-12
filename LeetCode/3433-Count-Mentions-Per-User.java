// 3433. Count Mentions Per User

class Solution {
    public int[] countMentions(int numberOfUsers, List<List<String>> events) {
        Comparator<List<String>> cmp = (a, b) -> {
            int t1 = Integer.parseInt(a.get(1));
            int t2 = Integer.parseInt(b.get(1));
            // make sure we first remove the users which are goinf offline
            if (t1 == t2 && a.get(0).equals("OFFLINE")) return -1; 
            return t1 - t2;
        };
        events.sort(cmp);

        int n = numberOfUsers;
        int[] ans = new int[n];
        Deque<List<Integer>> offline = new LinkedList<>();

        Set<Integer> online = new HashSet<>();
        for (int i = 0; i < n; i++) online.add(i);
        int all = 0;

        for (List<String> e : events) {
            int timeStamp = Integer.parseInt(e.get(1));
            while (!offline.isEmpty() && offline.peekLast().get(0) <= timeStamp) {
                online.add(offline.pollLast().get(1));
            }
            if (e.get(0).equals("MESSAGE")) {
                if (e.get(2).equals("ALL")) {
                    all++;
                }
                else if (e.get(2).equals("HERE")) {
                    for (int o : online) {
                        ans[o]++;
                    }
                }
                else {
                    String mentions[] = e.get(2).split(" ");
                    for (String m : mentions) {
                        ans[Integer.parseInt(m.substring(2))]++;
                    }
                }
            }
            else {
                int id = Integer.parseInt(e.get(2));
                online.remove(id);
                offline.addFirst(Arrays.asList(timeStamp + 60, id));
            }
        }
        for (int i = 0; i < n; i++) ans[i] += all;
        return ans;
    }
}
