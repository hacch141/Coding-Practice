// 977. Squares of a Sorted Array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int low = 0;
        int high = n-1;
        
        while(low <= high) {
            int maxi = max(nums[low]*nums[low],nums[high]*nums[high]);
            if(maxi == nums[low]*nums[low]) {
                low++;
            }
            else {
                high--;
            }
            ans.push_back(maxi);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
