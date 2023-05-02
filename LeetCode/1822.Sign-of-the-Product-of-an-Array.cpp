// 1822. Sign of the Product of an Array

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for(auto i : nums) {
            if(i==0) {
                return 0;
            }
            else if(i<0) {
                ans = (ans*-1);
            }
        }
        return ans;
    }
};
