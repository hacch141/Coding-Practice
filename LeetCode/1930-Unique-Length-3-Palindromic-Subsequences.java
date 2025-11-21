// 1930. Unique Length-3 Palindromic Subsequences

class Solution {
    int[][] pref;
    public int getFreq(int ind, int l, int r) {
        int f = pref[ind][r];
        if (l > 0) f -= pref[ind][l - 1];
        return f;
    }

    public int countPalindromicSubsequence(String s) {
        int n = s.length();

        pref = new int[26][n];
        for (int i = 0; i < n; i++) {
            pref[s.charAt(i) - 'a'][i]++;
        }

        for (int j = 1; j < n; j++) {
            for (int i = 0; i < 26; i++) {
                pref[i][j] += pref[i][j - 1];
            }
        }

        Set<String> st = new HashSet<>();
        for (int j = 1; j < n - 1; j++) {
            for (int i = 0; i < 26; i++) {
                if (getFreq(i, 0, j - 1) > 0 && getFreq(i, j + 1, n - 1) > 0) {
                    st.add("" + (char)(i + 'a') + s.charAt(j));
                }
            }
        }

        return st.size();
    }
}
