// Power Of Numbers

// Recursion
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(x==1 || x==0) return x;

        // for n = -2147483648 we convert this n to positive and it is overflow 
        // Hence we used 1times * -(n+1)times
        if(n<0) return 1/x*myPow(1/x,-(n+1));

        double half = myPow(x,n/2);
        double ans = half*half;
        if(n%2 == 1) {
            ans = ans*x;
        }

        return ans;
    }
};
// T : O(Log N)
// S : O(Log N)


// Iterative
class Solution {
public:
    double myPow(double x, int n) {
        double num = x;
        long long pow = n;
        double ans = 1;

        if(n<0) {
            pow = -(1LL*n);
        }

        while(pow) {
            if(pow&1) {
                ans = ans*num;
            }
            num = (num*num);
            pow >>= 1;
        }
        
        return n > 0 ? ans : 1/ans;
    }
};
// T : O(Log N)
// S : O(1)
