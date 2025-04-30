// 1295. Find Numbers with Even Number of Digits

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto i : nums) {
            int cnt = 0;
            while(i > 0) {
                cnt++;
                i /= 10;
            }
            ans += cnt % 2 == 0;
        }
        return ans;
    }
};
