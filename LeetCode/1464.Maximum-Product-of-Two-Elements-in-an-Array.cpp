// 1464. Maximum Product of Two Elements in an Array

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1 = INT_MIN, mx2 = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > mx1) {
                mx2 = mx1;
                mx1 = nums[i];
            }
            else if(nums[i] > mx2) {
                mx2 = nums[i];
            }
        }
        return (mx1-1)*(mx2-1);
    }
};
