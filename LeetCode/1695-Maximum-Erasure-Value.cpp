// 1695. Maximum Erasure Value

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, ans = 1, curr_sum = 0;
        unordered_set<int> st;
        for(int r = 0; r < n; r++) {
            while(st.count(nums[r])) {
                st.erase(nums[l]);
                curr_sum -= nums[l];
                l++;
            }
            curr_sum += nums[r];
            st.insert(nums[r]);
            ans = max(ans, curr_sum);
        }
        return ans;
    }
};
