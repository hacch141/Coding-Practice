class Solution {
    int[][] dp;
    Map<String, Set<String>> mp;
    
    public Set<String> solve(int i, int j, int n1, int n2, String s1, String s2) {
        Set<String> ans = new HashSet<>();

        if (i < 0 || j < 0) return ans;

        if (i == 0 && j == 0) {
            if (dp[0][0] == 1) ans.add(s1.charAt(0) + "");
            return ans;
        }
        
        String key = i + "_" + j;
        if (mp.containsKey(key)) return mp.get(key);

        if (s1.charAt(i) == s2.charAt(j)) {
            Set<String> cross = solve(i - 1, j - 1, n1, n2, s1, s2);
            for (String s : cross) {
                ans.add(s + s1.charAt(i));
            }
            if (ans.size() == 0) ans.add(s1.charAt(i) + "");
        }
        else {
            Set<String> top = solve(i - 1, j, n1, n2, s1, s2);
            Set<String> left = solve(i, j - 1, n1, n2, s1, s2);

            if (i == 0) ans = left;
            else if (j == 0) ans = top;
            else {
                if (dp[i - 1][j] > dp[i][j - 1]) ans = top;
                else if (dp[i - 1][j] < dp[i][j - 1]) ans = left;
                else {
                    ans.addAll(top);
                    ans.addAll(left);
                }
            }
        }
        
        mp.put(key, ans);
        return ans;
    }
    
    public List<String> allLCS(String s1, String s2) {
        // Code here
        int n1 = s1.length(), n2 = s2.length();
        dp = new int[n1][n2];
        
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    if (i > 0) dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
                    if (j > 0) dp[i][j] = Math.max(dp[i][j], dp[i][j - 1]);
                }
            }
        }
        
        mp = new HashMap<>();
        List<String> ans = new ArrayList<>(solve(n1 - 1, n2 - 1, n1, n2, s1, s2));
        Collections.sort(ans);

        return ans;
    }
}
