// 1512. Number of Good Pairs

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> help(101,0);
        int ans = 0;
        for(auto i : nums) {
            ans += help[i]++;
        }
        return ans;
    }
};
