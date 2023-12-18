class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int mx1 = INT_MIN, mx2 = INT_MIN, mn1 = INT_MAX, mn2 = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > mx1) {
                mx2 = mx1;
                mx1 = nums[i];
            }
            else if(nums[i] > mx2) {
                mx2 = nums[i];
            }

            if(nums[i] < mn1) {
                mn2 = mn1;
                mn1 = nums[i];
            }
            else if(nums[i] < mn2) {
                mn2 = nums[i];
            }
        }

        return (mx1*mx2) - (mn1*mn2);
    }
};
