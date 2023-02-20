// 34. Find First and Last Position of Element in Sorted Array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        int low = 0;
        int high = nums.size()-1;
        int idx = INT_MIN;
        while(low<=high) {
            int mid = (high-low)/2 + low;
            if(nums[mid] == target) {
                idx = mid;
                break;
            }
            else if(target < nums[mid]) {
                high = mid-1;
            }
            else if(target > nums[mid]) {
                low = mid+1;
            }
        }
        if(idx == INT_MIN) return {-1,-1};
        int leftidx = idx;
        int rightidx = idx;
        low = 0;
        high = nums.size()-1;

        while(low<=leftidx) {
            int mid = (leftidx-low)/2 + low;
            if(nums[mid]==target) {
                leftidx = mid-1;
            }
            else {
                low = mid+1;
            }
        }

        while(rightidx<=high) {
            int mid = (high-rightidx)/2 + rightidx;
            if(nums[mid]==target) {
                rightidx = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return {leftidx+1,rightidx-1};
    }
};
