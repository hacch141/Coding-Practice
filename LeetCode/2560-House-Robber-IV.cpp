// 2560. House Robber IV

class Solution {
public:
    bool ok(int mid, vector<int>& nums, int k) {
        int prev = -2, cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(prev + 1 != i && nums[i] <= mid) {
                cnt++;
                prev = i;
            }
        }
        return cnt >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        int low = 0, high = nums.size() - 1, ans;
        while(low <= high) {
            int mid = (high - low) / 2 + low;
            if(ok(v[mid], nums, k)) {
                ans = v[mid];
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
