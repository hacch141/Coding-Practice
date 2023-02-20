// 35. Search Insert Position


class Solution {
public:

    int bfs(int start, int end, vector<int>& nums, int target) {
        if(start > end) return start;
        int mid = (start+end)/2;
        if(nums[mid]==target) return mid;
        else if(target<nums[mid])  {
            return bfs(start,mid-1,nums,target);
        }
        else if(target>nums[mid])  {
            return bfs(mid+1,end,nums,target);
        }
        return 0;
    }

    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        return bfs(low,high,nums,target);
    }
};




class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low <= high) {
            int mid = (low+high)/2;
            if(target == nums[mid]) {
                return mid;
            }
            if(target < nums[mid]) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return low;
    }
};
