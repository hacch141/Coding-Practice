// 2342. Max Sum of a Pair With Equal Sum of Digits

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<vector<int>> v(82, vector<int>(2, -1));
        for(auto &i : nums) {
            int digit_sum = 0, tmp = i;
            while(tmp) {
                digit_sum += tmp % 10;
                tmp /= 10;
            }
            if(i >= v[digit_sum][0]) {
                v[digit_sum][1] = v[digit_sum][0];
                v[digit_sum][0] = i;
            }
            else if(i > v[digit_sum][1]) {
                v[digit_sum][1] = i;
            }
        }

        int ans = 0;
        for(auto &i : v) {
            if(i[0] != -1 && i[1] != -1) ans = max(ans, i[0] + i[1]);
        }
        return ans != 0 ? ans : -1;
    }
};
