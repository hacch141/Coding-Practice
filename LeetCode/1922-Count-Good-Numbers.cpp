// 1922. Count Good Numbers

class Solution {
public:
    long long num_pow(long long num, long long pow, long long mod) {
        long long ans = 1;
        while(pow) {
            if(pow & 1) {
                ans *= num;
                ans %= mod;
            }
            pow >>= 1;
            num = num * num;
            num %= mod;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long mod = 1e9 + 7;
        long long ans = 1;
        if(n & 1) {
            ans *= num_pow(5, (n + 1) / 2, mod);
            ans %= mod;
        }
        else {
            ans *= num_pow(5, n / 2, mod);
            ans %= mod;
        }
        ans *= num_pow(4, n / 2, mod);
        ans %= mod;
        return (int)ans;
    }
};
