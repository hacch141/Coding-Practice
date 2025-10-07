// 1488. Avoid Flood in The City

class Solution {
    public int[] avoidFlood(int[] rains) {
        int n = rains.length;
    
        int[] ans = new int[n];
        Map<Integer,Integer> lastDay = new HashMap<>(); // <lake,day>
        TreeSet<Integer> freeDays = new TreeSet<>();

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                freeDays.add(i);
                ans[i] = 1;
            }
            else {
                if (lastDay.containsKey(rains[i])) {
                    int lastRainDay = lastDay.get(rains[i]);
                    Integer dryDay = freeDays.higher(lastRainDay);
                    if (dryDay == null) return new int[0];
                    freeDays.remove(dryDay);
                    ans[dryDay] = rains[i];
                }
                lastDay.put(rains[i], i);
                ans[i] = -1;
            }
        }

        return ans;
    }
}
