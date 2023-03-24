// 2348. Number of Zero-Filled Subarrays

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long cnt = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            while(i<n && nums[i]==0) {
                cnt++;
                i++;
            }
            ans += (long long)(cnt*(cnt+1))/2;
            cnt = 0;
        }
        return ans;
    }
};
