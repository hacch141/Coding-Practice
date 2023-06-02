// 50. Pow(x, n)

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long pow = n;
        if(n<0) {
            pow = -pow;
        }

        while(pow) {
            if(pow&1) {
                ans = ans*x;            
            }
            x = x*x;
            pow >>= 1;
        }

        if(n<0) ans = 1.0/ans;
        return ans;
    }
};

// T : O(Log N)
// S : O(1)
