// 2780. Minimum Index of a Valid Split

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int dominant_element = nums[0], cnt = 0;
        for(auto &i : nums) {
            if(cnt == 0) {
                dominant_element = i;
                cnt++;
            }
            else if(i == dominant_element) {
                cnt++;
            }
            else {
                cnt--;
            }
        }

        int dominant_cnt = 0;
        for(auto &i : nums) dominant_cnt += i == dominant_element;

        int left_cnt = 0, right_cnt = 0;
        for(int i = 0; i < n; i++) {
            left_cnt += nums[i] == dominant_element;
            right_cnt = dominant_cnt - left_cnt;
            if(left_cnt * 2 > i + 1 && right_cnt * 2 > n - i - 1) {
                return i;
            }
        }

        return -1;
    }
};
