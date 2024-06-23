// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> st;
        int n = nums.size(), l = 0, ans = 0;
        for(int r = 0; r < n; r++) {
            st.insert(nums[r]);
            int mn = *st.begin(), mx = *st.rbegin();
            while(!st.empty() && mx - mn > limit) {
                st.erase(st.find(nums[l]));
                l++;
                mn = *st.begin(), mx = *st.rbegin();
            }
            ans = max(ans, (int)st.size());
        }
        return ans;
    }
};
