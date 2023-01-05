// 128. Longest Consecutive Sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return nums.size();
        set<int> s(nums.begin(),nums.end());
        int ans = 1;
        int cnt = 1;
        for(auto it : nums) {
            int curr = it;
            if(!s.count(curr-1)) {
                while(s.count(curr+1)) {
                    cnt++;
                    curr++;
                }
                ans = max(ans,cnt);
                cnt = 1;
            }
        }
        return ans;
    }
};
