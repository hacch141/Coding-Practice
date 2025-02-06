// 1726. Tuple with Same Product

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<long long, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                mp[1LL * nums[i] * nums[j]]++;
            }
        }

        int ans = 0;
        for(auto &it : mp) {
            if(it.second > 1) {
                ans += 8 * ((it.second * (it.second - 1)) / 2);
            }
        }

        return ans;
    }
};
