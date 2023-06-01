// 29. Divide Two Integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        long long a = abs(dividend);
        long long b = abs(divisor);

        long long quotient = 0;

        for(int i=31; i>=0; i--) {
            if((b<<i) <= a) {
                quotient += 1LL<<i;
                a -= (b<<i); 
                if(i==31) return sign==1 ? INT_MAX : INT_MIN;
            }
        }

        return sign*quotient;
    }
};

// T : O(Log N)
// S : O(1)
