// 1658. Minimum Operations to Reduce X to Zero

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int sum=0;
        for(auto ele : nums) {
            sum += ele;
        }
        if(sum < x) return -1;

        int target = sum - x;
        int currSum=0, i=0, j=0;
        int ans = INT_MAX;

        while(j<n) {
            currSum += nums[j];
            while(i<n && currSum > target) {
                currSum -= nums[i];
                i++;
            }
            if(currSum == target) {
                ans = min(ans , n-(j-i+1));
            }
            j++;
        }
        return ans==INT_MAX ? -1 : ans;
    }
};
