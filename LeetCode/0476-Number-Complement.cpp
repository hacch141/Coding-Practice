// 476. Number Complement

class Solution {
public:
    int findComplement(int num) {
        int ans = 0, bit = 0;
        while(num > 0) {
            if((num & 1) == 0) {
                ans |= (1 << bit);
            }
            bit++;
            num >>= 1;
        }
        return ans;
    }
};
