// 1780. Check if Number is a Sum of Powers of Three

class Solution {
public:
    bool checkPowersOfThree(int n) {
        long long mask = 0;
        while(n > 0) {
            if(n % 3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};
