// 2089. Find Target Indices After Sorting Array

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int tar_cnt = 0;
        int less_cnt = 0;
        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(nums[i]<target) less_cnt++;
            if(nums[i]==target) tar_cnt++;
        }
        for(int i=0; i<tar_cnt; i++) {
            ans.push_back(i+less_cnt);
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(nums[i]==target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
