// Count Good Numbers

// Recursion
class Solution {
public:

    int  mod = 1e9+7;
    long long numpow(long long num, long long pow) {
        if(num == 0 || num == 1) return num;
        if(pow == 0) return 1;

        if(pow<0) return (1/num)*(numpow(1/num,-pow-1));

        long long half = numpow(num,pow/2);
        long long ans = (half*half) % mod;

        if(pow%2 == 1) {
            ans = (ans*num) % mod;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long evens = n/2 + (n%2);
        long long odds = n - evens;
        return (int)((numpow(5,evens) * numpow(4,odds)) % mod);
    }
};
// T : O(Log N)
// S : O(Log N)


// Iterative
class Solution {
public:
    int  mod = 1e9+7;
    long long numpow(long long num, long long pow) {
        long long ans = 1;
        long long A = num;
        while(pow) {
            if(pow&1) {
                ans = (ans * A)%mod;
            }
            A = (A*A)%mod;
            pow >>= 1;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long evens = n/2 + (n%2);
        long long odds = n - evens;
        return (int)((numpow(5,evens) * numpow(4,odds)) % mod);
    }
};
// T : O(Log N)
// S : O(1)
