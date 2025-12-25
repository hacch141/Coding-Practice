// 904. Fruit Into Baskets

class Solution {
    public int totalFruit(int[] fruits) {
        int n = fruits.length;
        int l = 0, r = 0, ans = 0;
        Map<Integer,Integer> mp = new HashMap<>();
        while (r < n) {
            int fR = fruits[r];
            mp.put(fR, mp.getOrDefault(fR, 0) + 1);
            while (mp.size() > 2) {
                int fL = fruits[l];
                mp.put(fL, mp.get(fL) - 1);
                if (mp.get(fL) == 0) mp.remove(fL);
                l++;
            }
            ans = Math.max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
}
