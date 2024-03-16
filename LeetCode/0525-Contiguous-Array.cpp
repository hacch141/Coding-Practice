// 525. Contiguous Array

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) nums[i] = -1;
        }
        map<int,int> mp;
        int sum = 0, ans = 0;
        mp[0] = -1;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(mp.find(sum) != mp.end()) {
                ans = max(ans, i - mp[sum]);
            }
            else {
                mp[sum] = i;
            }
        }
        return ans;
    }
};
