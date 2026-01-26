// Minimum Window Subsequence

class Solution {
    public String minWindow(String s1, String s2) {
        // code here
        int n = s1.length(), m = s2.length();
        int[][] nextPos = new int[n][26];

        for (int i = 0; i < n; i++) {
            Arrays.fill(nextPos[i], -1);
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                if (i + 1 < n) nextPos[i][j] = nextPos[i + 1][j];
            }
            nextPos[i][s1.charAt(i) - 'a'] = i;
        }
        
        String ans = "";
        int mn = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            if (s1.charAt(i) != s2.charAt(0)) continue;
            int end = i, p = 0;
            while (p < m && end < n && nextPos[end][s2.charAt(p) - 'a'] != -1) {
                end = nextPos[end][s2.charAt(p) - 'a'];
                end++;
                p++;
            }
            if (p == m) {
                if (end - i < mn) {
                    mn = end - i;
                    ans = s1.substring(i, i + mn);
                }
            }
        }

        return ans;
    }
}
