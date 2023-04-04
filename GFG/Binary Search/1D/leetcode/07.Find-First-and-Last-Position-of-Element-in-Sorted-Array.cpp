// 34. Find First and Last Position of Element in Sorted Array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(n==0) return {-1,-1};

        int first, last;
    
        int low = 0;
        int high = n-1;
        bool flag = false;
        
        // binary search for first occurance
        while(low<=high) {
            int mid = (high-low)/2 +low;
            if(nums[mid]==target) flag = true;
            if(nums[mid] >= target) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        first = low;
        
        
        low = 0;
        high = n-1;
        
        // binary search for last occurance
        while(low<=high) {
            int mid = (high-low)/2 +low;
            if(nums[mid] <= target) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        last = high;
        
        if(!flag) return {-1,-1};
        return {first,last};
    }
};
