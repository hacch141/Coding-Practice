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
// TC : O(N*(Log(Log N)))
// Outer loop (for int i = 2; i * i <= 1e6; i++):
// The total number of times is_prime[j] = false is executed across all iterations is roughly 
// n/2 + n/3 + n/5 + n/7 + ..., (Known as Harmonic Series)
// which sums up to O(n log log n).

//===========================

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int prevPrime = -1, closestA = -1, closestB = -1;
        int minDifference = 1e6;
        // Find all prime numbers in the given range
        for (int candidate = left; candidate <= right; candidate++) {
            if (isPrime(candidate)) {
                if (prevPrime != -1) {
                    int difference = candidate - prevPrime;
                    if (difference < minDifference) {
                        minDifference = difference;
                        closestA = prevPrime;
                        closestB = candidate;
                    }
                    // Twin prime optimization
                    if (difference == 2 or difference == 1)
                        return {prevPrime, candidate};
                }
                prevPrime = candidate;
            }
        }

        return (closestA == -1) ? vector<int>{-1, -1}
                                : vector<int>{closestA, closestB};
    }

private:
    bool isPrime(int number) {
        if (number < 2) return false;
        if (number == 2 || number == 3) return true;
        if (number % 2 == 0) return false;
        for (int divisor = 3; divisor * divisor <= number; divisor += 2) {
            if (number % divisor == 0) return false;
        }
        return true;
    }
};
// TC : O(N * √N)
