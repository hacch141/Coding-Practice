// 75. Sort Colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                cnt0++;
            }
            else if(nums[i] == 1) {
                cnt1++;
            }
            else if(nums[i] == 2) {
                cnt2++;
            }
        }
        
        for(int i=0; i<cnt0; i++) {
            nums[i] = 0;
        }
        for(int i=0; i<cnt1; i++) {
            nums[i+cnt0] = 1;
        }
        for(int i=0; i<cnt2; i++) {
            nums[i+cnt0+cnt1] = 2;
        }
    }
};
