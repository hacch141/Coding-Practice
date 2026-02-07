// 1653. Minimum Deletions to Make String Balanced

class Solution {
    public int getSum(int[] f, int l, int r) {
        int n = f.length;
        int ans = f[r];
        if (l > 0) ans -= f[l - 1];
        return ans;
    }

    public int minimumDeletions(String s) {
        int n = s.length();
        int[] fa = new int[n];
        int[] fb = new int[n];
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if (i > 0) {
                fa[i] += fa[i - 1];
                fb[i] += fb[i - 1];
            }
            if (ch == 'a') {
                fa[i]++;
            }
            else {
                fb[i]++;
            }
        }

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i <= n; i++) {
            int curr = 0;
            if (i > 0) curr += getSum(fb, 0, i - 1);
            if (i < n) curr += getSum(fa, i, n - 1);
            ans = Math.min(ans, curr);
        }

        return ans;
    }
}
