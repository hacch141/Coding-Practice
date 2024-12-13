// 2593. Find Score of an Array After Marking All Elements

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        set<pair<int,int>> st;
        int n = nums.size();
        for(int i = 0; i < n; i++) st.insert({nums[i], i});
        while(!st.empty()) {
            auto it = *st.begin();
            st.erase(it);
            int val = it.first, ind = it.second;
            ans += val;
            if(ind < n - 1 && st.count({nums[ind + 1], ind + 1})) st.erase(st.find({nums[ind + 1], ind + 1}));
            if(ind > 0 && st.count({nums[ind - 1], ind - 1})) st.erase(st.find({nums[ind - 1], ind - 1}));
        }
        return ans;
    }
};
