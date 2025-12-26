// 76. Minimum Window Substring

class Solution {
    boolean isIncludeT(Map<Character,Integer> mp) {
        for (int f : mp.values()) {
            if (f > 0) return false;
        }
        return true;
    }

    public String minWindow(String s, String t) {
        int n = s.length();

        Map<Character,Integer> mp = new HashMap<>();
        for (char ch : t.toCharArray()) mp.put(ch, mp.getOrDefault(ch, 0) + 1);

        int l = 0, r = 0, mn = Integer.MAX_VALUE;
        String ans = "";
        while (r < n) {
            char ch = s.charAt(r);
            if (mp.containsKey(ch)) mp.put(ch, mp.get(ch) - 1);
            while (isIncludeT(mp)) {
                if (r - l + 1 < mn) {
                    mn = r - l + 1;
                    ans = s.substring(l, l + mn);
                }
                ch = s.charAt(l);
                if (mp.containsKey(ch)) mp.put(ch, mp.get(ch) + 1);
                l++;
            }
            r++;
        }
        return ans;
    }
}
