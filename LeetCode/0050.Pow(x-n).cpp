// 50. Pow(x, n)

// Recursion
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(x==1 || x==0) return x;
        if(n<0) return 1/x*myPow(1/x,-(n+1));

        double half = myPow(x,n/2);
        double ans = half*half;
        if(n%2 == 1) {
            ans = ans*x;
        }

        return ans;
    }
};



// Iterative
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
