// 3371. Identify the Largest Outlier in an Array

class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size(), sum = 0, ans = INT_MIN;
        for(auto i : nums) {
            mp[i]++;
            sum += i;
        }
        for(int i = 0; i < n; i++) {
            int out = nums[i];
            mp[out]--;
            sum -= out;
            if(sum % 2  == 0) {
                if(mp[sum / 2] > 0) {
                    ans = max(ans, out);
                }
            }
            sum += out;
            mp[out]++;
        }
        return ans;
    }
};
