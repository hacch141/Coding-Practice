// 2523. Closest Prime Numbers in Range

class Solution {
public:

    vector<bool> is_prime;
    bool sieve_done;

    Solution() {
        is_prime = vector<bool>(1e6 + 1, true);
        is_prime[0] = is_prime[1] = false;  // 0 and 1 are not prime
        sieve_done = false;
    }

    void sieve() {
        is_prime[0] = is_prime[1] = false;  // 0 and 1 are not prime
        for(int i = 2; i * i <= 1e6; i++) {
            if(is_prime[i]) {
                for(int j = i * i; j <= 1e6; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        sieve_done = true;
    }

    vector<int> closestPrimes(int left, int right) {
        if (!sieve_done) sieve();  // Run sieve once
        vector<int> ans(2, -1);
        int prev = -1;
        for(int i = left; i <= right; i++) {
            if(is_prime[i]) {
                if(ans[0] == -1) ans[0] = i;
                else if(ans[1] == -1) ans[1] = i;
                else if(i - prev < ans[1] - ans[0]){
                    ans[0] = prev;
                    ans[1] = i;
                }
                prev = i;
            }
        }
        if(ans[0] != -1 && ans[1] == -1) ans[0] = -1;
        return ans;
    }
};
