// 632. Smallest Range Covering Elements from K Lists

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        multiset<vector<int>> st;
        for(int i = 0; i < n; i++) {
            st.insert({nums[i][0], i, 0});
        }
        vector<int> ans(2);
        ans[0] = -1e5, ans[1] = 1e5;
        while(1) {
            int diff = (*st.rbegin())[0] - (*st.begin())[0];
            if(diff < ans[1] - ans[0]) {
                ans[0] = (*st.begin())[0];
                ans[1] = (*st.rbegin())[0];
            }
            int i = (*st.begin())[1], j = (*st.begin())[2];
            if(j + 1 == nums[i].size()) break;
            st.erase(st.begin());
            st.insert({nums[i][j + 1], i, j + 1});
        }
        return ans;
    }
};
