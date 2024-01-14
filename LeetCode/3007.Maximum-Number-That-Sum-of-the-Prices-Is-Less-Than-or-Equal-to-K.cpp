// 3007. Maximum Number That Sum of the Prices Is Less Than or Equal to K

#define ll long long

ll bits[60];

class Solution {
public:
    
    void cnt_bits(ll n) {
        if(n == 0) return;
        if(n == 1) {
            bits[0]++;
            return;
        }
        if(n == 2) {
            bits[0]++;
            bits[1]++;
            return;
        }
        
        ll msb = log2(n);
        ll cn = (1LL << msb);
        bits[msb] += (n - cn + 1);
        for(int i = 0; i < msb; i++) {
            bits[i] += (cn / 2);
        }
        cnt_bits(n - cn);
    }
    
    bool ok(ll num, ll& k, int& x) {
        for(int i = 0; i < 60; i++) {
            bits[i] = 0;
        }
        cnt_bits(num);
        ll cnt = 0;
        for(int i = 0; i < 60; i++) {
            if((i+1) % x == 0) {
                cnt += bits[i];
            }
        }
        return cnt <= k;
    }
    
    long long findMaximumNumber(long long k, int x) {
        ll l = 0, h = 1e17, ans = 0;
        while(l <= h) {
            ll mid = (h-l)/2 + l;
            if(ok(mid, k, x)) {
                ans = mid;
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        return ans;
    }
};
