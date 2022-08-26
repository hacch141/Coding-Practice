// 869. Reordered Power of 2

class Solution {
public:
    long count(int n) {
        long res = 0;
        while(n > 0) {
            res += pow(10,n%10);
            n /= 10;
        }
        return res;
    }
    
    bool reorderedPowerOf2(int n) {
        long num = count(n);
        for (int i = 0; i < 32; i++) {
            if (count(1 << i) == num) {
                return true;
            }
        }
        return false;
    }
};
