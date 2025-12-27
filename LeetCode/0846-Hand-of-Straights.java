// 846. Hand of Straights

class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        Map<Integer,Integer> mp = new TreeMap<>();
        for (int i : hand) mp.put(i, mp.getOrDefault(i, 0) + 1);

        for (int start : mp.keySet()) {
            int f = mp.get(start);
            if (f == 0) continue;
            for (int i = 0; i < groupSize; i++) {
                if (!mp.containsKey(start + i) || mp.get(start + i) < f) return false;
                mp.put(start + i, mp.get(start + i) - f);
            }
        }

        return true;
    }
}
