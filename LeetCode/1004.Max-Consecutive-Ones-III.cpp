// 1004. Max Consecutive Ones III

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0, ans=0, n=nums.size(), cnt0=0;

        for(r=0; r<n; r++) {
            if(nums[r] == 0) {
                cnt0++;
            }
            while(cnt0 > k) {
                if(nums[l] == 0) {
                    cnt0--;
                }
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
