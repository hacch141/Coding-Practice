// 3375. Minimum Operations to Make Array Values Equal to K

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        if(*min_element(nums.begin(), nums.end()) < k) return -1;
        set<int> st;
        for(auto i : nums) st.insert(i);
        if(*st.begin() == k) return st.size() - 1;
        return st.size();
    }
};
