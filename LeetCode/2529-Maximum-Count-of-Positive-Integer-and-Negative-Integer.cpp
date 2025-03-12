// 2529. Maximum Count of Positive Integer and Negative Integer

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        for(auto &i : nums) {
            pos += i > 0;
            neg += i < 0;
        }
        return max(pos, neg);
    }
};
