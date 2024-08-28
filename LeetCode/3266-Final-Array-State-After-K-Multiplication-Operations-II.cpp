// 3266. Final Array State After K Multiplication Operations II

#define ll long long

class Solution {
public:
    ll powmod(ll num, ll p, ll mod) {
        ll result = 1;
        num %= mod;
        while (p > 0) {
            if (p & 1) {
                result = (result * num) % mod;
            }
            num = (num * num) % mod;
            p >>= 1;
        }
        return result;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier == 1) return nums;
        int n = nums.size(), cnt = 0, mx = *max_element(nums.begin(), nums.end()), mod = 1e9 + 7;
        for(auto i : nums) {
            while(1LL * i * multiplier <= mx) {
                cnt++;
                i *= multiplier;
            }
        }

        vector<int> ans(n);
        if(k <= cnt) {
            priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
            for(int i = 0; i < n; i++) {
                pq.push({nums[i], i});
            }
            while(k--) {
                ll num = pq.top().first, ind = pq.top().second;
                pq.pop();
                pq.push({num * multiplier, ind});
            }
            while(!pq.empty()) {
                ll num = pq.top().first, ind = pq.top().second;
                pq.pop();
                ans[ind] = num % mod;
            }
        }
        else {
            vector<pair<ll,int>> v;
            for(int i = 0; i < n; i++) {
                ll num = nums[i];
                while(num * multiplier <= mx) {
                    num *= multiplier;
                    k--;
                }
                v.push_back({num, i});
            }
            sort(v.begin(),v.end());

            int pw = k / n;
            int md = k % n;

            for(int i = 0; i < n; i++) {
                ll mul;
                if(i < md) mul = powmod(multiplier, pw + 1, mod);
                else mul = powmod(multiplier, pw, mod);
                ans[v[i].second] = (v[i].first * mul) % mod;
            }
        }
        return ans;
    }
};
