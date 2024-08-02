// 2134. Minimum Swaps to Group All 1's Together II

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> v;
        for(auto i : nums) v.push_back(i);
        for(auto i : nums) v.push_back(i);

        int c1 = 0, c0 = 0, l = 0, ans = n;
        for(auto i : nums) c1 += i == 1;
        
        for(int r = 0; r < 2 * n; r++) {
            c0 += v[r] == 0;
            if(r - l + 1 > c1) {
                c0 -= v[l] == 0;
                l++;
            }
            if(r - l + 1 == c1) ans = min(ans, c0);
        }
        return ans;
    }
};
