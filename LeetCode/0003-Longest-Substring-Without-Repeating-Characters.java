// 3. Longest Substring Without Repeating Characters

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        Map<Character,Integer> mp = new HashMap<>();
        int l = 0, r = 0, ans = 0;
        while (r < n) {
            char chL = s.charAt(l), chR = s.charAt(r);
            mp.put(chR, mp.getOrDefault(chR, 0) + 1);
            while (mp.get(chR) > 1) {
                chL = s.charAt(l);
                mp.put(chL, mp.get(chL) - 1);
                l++;
            }
            ans = Math.max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
}
