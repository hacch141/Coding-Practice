// 2573. Find the String with LCP

class Solution {
    public String findTheString(int[][] lcp) {
        int n = lcp.length;

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) sb.append('#');

        boolean[] vis = new boolean[26];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (lcp[i][j] > 0) {
                    sb.setCharAt(i, sb.charAt(j));
                    break;
                }
            }

            if (sb.charAt(i) == '#') {
                for (int j = 0; j < 26; j++) {
                    if (vis[j] == false) {
                        sb.setCharAt(i, (char)(j + 'a'));
                        vis[j] = true;
                        break;
                    }
                }
            }

            if (sb.charAt(i) == '#') return "";
        }

        for (int j = n - 1; j >= 0; j--) {
            for (int i = n - 1; i >= 0; i--) {
                if (sb.charAt(i) == sb.charAt(j)) {
                    int curr = 1;
                    if (i + 1 < n && j + 1 < n) curr += lcp[i + 1][j + 1];
                    if (lcp[i][j] != curr) return "";
                }
                else {
                    if (lcp[i][j] != 0) return "";
                }
            }
        }

        return sb.toString();
    }
}
