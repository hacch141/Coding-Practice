// 1680. Concatenation of Consecutive Binary Numbers

class Solution {
    int MOD = (int)1e9 + 7;
    public int concatenatedBinary(int n) {

        int ans = 1;

        for (int i = 2; i <= n; i++) {

            boolean start = false;

            for (int j = 31; j >= 0; j--) {

                boolean isJthBitSet = ((i >> j) & 1) != 0;
                if (isJthBitSet && !start) start = true;

                if (start) {
                    ans <<= 1;
                    if (isJthBitSet) ans++;
                    ans %= MOD;
                }

            }
        }

        return ans;
    }
}
