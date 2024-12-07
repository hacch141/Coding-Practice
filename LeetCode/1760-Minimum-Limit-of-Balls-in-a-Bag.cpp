// 1760. Minimum Limit of Balls in a Bag

class Solution {
public:
    bool ok(vector<int>& nums, int maxOperations, int mid) {
        int cnt = 0;
        for(auto i : nums) {
            cnt += ((i + mid - 1) / mid);
            cnt--;
        }
        return cnt <= maxOperations;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size(), low = 1, high = *max_element(nums.begin(), nums.end()), ans = high;
        while(low <= high) {
            int mid = (high - low) / 2 + low;
            if(ok(nums, maxOperations, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
