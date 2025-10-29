// 3370. Smallest Number With All Set Bits

class Solution {
    public int smallestNumber(int n) {
        int left_most = 0;
        while(n > 0) {
            n >>= 1;
            left_most++;
        }
        return (1 << left_most) - 1;
    }
}
