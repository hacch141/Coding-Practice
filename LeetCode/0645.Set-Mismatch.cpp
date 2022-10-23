// 645. Set Mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        vector<int> ans;
        int sum = 0;
        for(int i=0; i<n; i++) {
            if(mp.find(nums[i]) != mp.end()) {
                ans.push_back(nums[i]);
            }
            sum += nums[i];
            mp[nums[i]]++;
        }
        ans.push_back((n*(n+1)/2)-sum+ans[0]);
        return ans;
    }
};
