// 16. 3Sum Closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0; i<n-2; i++) {
            int sum1 = nums[i];
            int left = i+1;
            int right = n-1;
            while(left<right) {
                int sum2 = nums[left]+nums[right];
                if(abs(target-sum1-sum2) < abs(target-closest)) {
                    closest = sum1+sum2;
                }
                if(sum1+sum2 < target) {
                    left++;
                }
                else if(sum1+sum2 > target) {
                    right--;
                }
                else {
                    return target;
                }
            }
            while(i<n-2 && nums[i]==nums[i+1])i++;
        }
        return closest;
    }
};
