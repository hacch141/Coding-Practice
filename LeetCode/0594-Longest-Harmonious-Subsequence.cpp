// 594. Longest Harmonious Subsequence

// Two-Pointer
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, ans = 0;
        for(int r = 0; r < n; r++) {
            while(nums[r] - nums[l] > 1) l++;
            if(nums[r] - nums[l] == 1)
                ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

// Counting
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i : nums) mp[i]++;

        int ans = 0;
        for(auto it : mp) {
            int num = it.first;
            int freq = it.second;
            if(mp.find(num + 1) != mp.end()) {
                ans = max(ans, freq + mp[num + 1]);
            }
        }
        return ans;
    }
};
