// 1248. Count Number of Nice Subarrays

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size(), odd = 0, ans = 0;
        mp[0] = 1;
        for(int i = 0; i < n; i++) {
            odd += nums[i] % 2;
            mp[odd]++;
            ans += mp[odd - k];
        }
        return ans;
    }
};
