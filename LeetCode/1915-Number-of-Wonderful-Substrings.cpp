// 1915. Number of Wonderful Substrings

using ll = long long;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        map<ll,ll> mp;
        mp[0] = 1;

        ll ans = 0, mask = 0;
        for(auto ch : word) {
            mask ^= (1LL << (ch - 'a'));
            ans += mp[mask];
            for(char ch = 'a'; ch <= 'j'; ch++) {
                ans += mp[mask ^ (1LL << (ch - 'a'))];
            }
            mp[mask]++;
        }
        return ans;
    }
};
