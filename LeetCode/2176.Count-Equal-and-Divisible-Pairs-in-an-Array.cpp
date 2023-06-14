// 2176. Count Equal and Divisible Pairs in an Array

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp;
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(mp.find(nums[i]) != mp.end()) {
                for(auto ind : mp[nums[i]]) {
                    if((i*ind)%k==0) ans++;
                }
            }
            mp[nums[i]].push_back(i);
        }
        return ans;
    }
};
