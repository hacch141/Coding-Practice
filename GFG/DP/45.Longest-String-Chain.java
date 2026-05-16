// Longest String Chain

class Solution {
    public boolean ok(String s1, String s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 + 1 != n2) return false;

        boolean f = true;
        int p1 = 0, p2 = 0;
        while (p1 < n1 && p2 < n2) {
            if (s1.charAt(p1) != s2.charAt(p2)) {
                if (!f) return false;
                f = false;
                p2++;
            }
            else {
                p1++;
                p2++;
            }
        }

        return true;
    }

    public int longestStrChain(String[] words) {
        int n = words.length;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        Arrays.sort(words, (a, b) -> (a.length() - b.length()));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((1 + dp[j] > dp[i]) && ok(words[j], words[i])) {
                    dp[i] = 1 + dp[j];
                }
            }
            ans = Math.max(ans, dp[i]);
        }

        return ans;
    }
}
