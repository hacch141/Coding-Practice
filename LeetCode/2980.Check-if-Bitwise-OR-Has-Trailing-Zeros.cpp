// 2980. Check if Bitwise OR Has Trailing Zeros

class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt = 0;
        for(auto i : nums) if((i & 1) == 0) cnt++;
        return cnt >= 2;
    }
};
