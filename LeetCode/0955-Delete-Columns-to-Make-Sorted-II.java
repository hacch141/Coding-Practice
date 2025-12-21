// 955. Delete Columns to Make Sorted II

class Solution {
    public boolean ok(String s1, String s2, boolean[] f) {
        for (int i = 0; i < s1.length(); i++) {
            if (f[i] && (s1.charAt(i) < s2.charAt(i))) return true;
            if (f[i] && (s1.charAt(i) > s2.charAt(i))) return false;
        }
        return true;
    }

    public int minDeletionSize(String[] strs) {
        int n = strs[0].length();
        boolean[] f = new boolean[n];
        for (int j = 0; j < strs[0].length(); j++) {
            f[j] = true;
            for (int i = 1; i < strs.length; i++) {
                if (!ok(strs[i - 1], strs[i], f)) {
                    f[j] = false;
                    break;
                }
            }
        }

        int ans = 0;
        for (boolean i : f) ans += i == false ? 1 : 0;
        return ans;
    }
}
