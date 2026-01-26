// 424. Longest Repeating Character Replacement

class Solution {
    public int solve(String s, int k, char ch) {
        int n = s.length();
        int l = 0, cnt = 0;
        int ans = 0;
        for (int r = 0; r < n; r++) {
            cnt += (s.charAt(r) != ch ? 1 : 0);
            while (cnt > k) {
                cnt -= (s.charAt(l) != ch ? 1 : 0);
                l++;
            }
            ans = Math.max(ans, r - l + 1);
        }
        return ans;
    }

    public int characterReplacement(String s, int k) {
        int n = s.length();
        int ans = 1;
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            ans = Math.max(ans, solve(s, k, ch));
        }
        return ans;
    }
}
