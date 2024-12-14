// 2762. Continuous Subarrays

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size(), l = 0;
        multiset<int> st;
        for(int r = 0; r < n; r++) {
            st.insert(nums[r]);
            while(*st.rbegin() - *st.begin() > 2) {
                st.erase(st.find(nums[l]));
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};
