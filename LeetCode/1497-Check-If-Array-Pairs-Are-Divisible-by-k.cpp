// 1497. Check If Array Pairs Are Divisible by k

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        long long K = k;
        map<long long,long long> mp;
        for(auto i : arr) {
            if(i < 0) {
                mp[(i + ((-i) * K)) % K]++;
            }
            else {
                mp[i % K]++;
            }
        }
        if(mp[0] % 2) return false;
        for(auto i : mp) {
            long long num = i.first;
            if(num == 0) continue;
            if(mp[num] != mp[K - num]) return false;
        }
        return true;
    }
};
