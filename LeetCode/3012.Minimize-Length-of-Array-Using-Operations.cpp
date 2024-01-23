// 3012. Minimize Length of Array Using Operations

class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int mn = 1e9 + 2, freq = 0;
        for(auto i : nums) mn = min(mn, i);
        for(auto i : nums) {
            freq += (i == mn);
            if(i % mn) return 1;
        }
        return (freq + 1)/2;
    }
};
