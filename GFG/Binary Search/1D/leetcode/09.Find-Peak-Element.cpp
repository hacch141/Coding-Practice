// 162. Find Peak Element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();
        int low = 0;
        int high = n-1;
        
        while(low<high) {
            
            int mid = (high-low)/2 + low;
            
            if(nums[mid+1]>nums[mid]) {
                low = mid+1;
            }

            else {
                high = mid;
            }
            
        }
        return low;
    }
};
