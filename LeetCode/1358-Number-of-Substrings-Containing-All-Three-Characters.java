// 1358. Number of Substrings Containing All Three Characters

class Solution {
    public int numberOfSubstrings(String s) {
        int n = s.length();
        int l = 0, r = 0;
        long ans = (1L * n * (n + 1)) / 2;
        int[] f = new int[3];
        while (r < n) {
            char ch = s.charAt(r);
            f[ch - 'a']++;
            while (f[0] != 0 && f[1] != 0 && f[2] != 0) {
                ch = s.charAt(l);
                f[ch - 'a']--;
                l++;
            }
            ans -= (r - l + 1);
            r++;
        }
        return (int)ans;
    }
}
