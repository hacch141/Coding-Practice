// 2501. Longest Square Streak in an Array

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        set<int> st;
        for(auto i : nums) mp[i] = 1;
        for(int i = 0; i < n; i++) {
            int sq = sqrt(nums[i]);
            if(sq * sq == nums[i] && !st.count(sq) && mp.find(sq) != mp.end()) {
                mp[nums[i]] = mp[sq] + 1;
                ans = max(ans, mp[nums[i]]);
                st.insert(sq);
            }
        }
        return ans == 0 ? -1 : ans;
    }
};
