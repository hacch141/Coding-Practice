// 485. Max Consecutive Ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int oneCount = 0, i = 0, ans = 0;
        for(int j=0; j<nums.size(); j++) {
            if(nums[j]==1)
                oneCount++;
            else oneCount = 0;
            ans = max(ans, oneCount);
        }
        return ans;
    }
};