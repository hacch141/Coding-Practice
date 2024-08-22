// 1009. Complement of Base 10 Integer

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int ans = 0, bit = 0;
        while(n > 0) {
            if((n & 1) == 0) {
                ans |= (1 << bit);
            }
            bit++;
            n >>= 1;
        }
        return ans;
    }
};
