// 3370. Smallest Number With All Set Bits

class Solution {
public:
    int smallestNumber(int n) {
        int ans = 0, bit = 0;
        while(n) {
            ans |= (1 << bit);
            bit++;
            n >>= 1;
        }
        return ans;
    }
};
