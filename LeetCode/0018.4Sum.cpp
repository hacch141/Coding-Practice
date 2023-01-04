// 18. 4Sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int left = j+1;
                int right = n-1;
                long long int sum1 = nums[i] + nums[j];
                while(left < right) {
                    int sum2 = nums[left]+nums[right];
                    if(sum1+sum2 < target) left++;
                    else if(sum1+sum2 > target) right--;
                    else {
                        vector<int> temp(4,0);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[left];
                        temp[3] = nums[right];
                        ans.push_back(temp);
                        while(left<right && nums[left]==temp[2]) left++;
                        while(left<right && nums[right]==temp[3]) right--;
                    }
                }
                while(j+1<n && nums[j+1]==nums[j]) j++;
            }
            while(i+1<n && nums[i+1]==nums[i]) i++;
        }
        return ans;
    }
};
