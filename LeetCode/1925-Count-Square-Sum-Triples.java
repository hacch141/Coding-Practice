// 1925. Count Square Sum Triples

class Solution {
    public int countTriples(int n) {
        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i; j < n; j++) {
                int c2 = (i * i) + (j * j);
                int c = (int)Math.sqrt(c2);
                if (c2 <= n * n && c2 == c * c) {
                    ans += (i != j) ? 2 : 1;
                }
            }
        }
        return ans;
    }
}
