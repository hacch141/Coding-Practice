// 974. Subarray Sums Divisible by K

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size(), pref = 0, ans = 0;
        mp[0] = 1;
        for(int i = 0; i < n; i++) {
            pref += nums[i];
            pref = ((pref % k) + k) % k;
            ans += mp[pref];
            mp[pref]++;
        }
        return ans;
    }
};
