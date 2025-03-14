// 2226. Maximum Candies Allocated to K Children

class Solution {
public:
    bool ok(int mid, vector<int>& candies, long long k) {
        long long cnt = 0;
        for(auto &i : candies) {
            cnt += (i / mid);
        }
        return cnt >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = 1e7, ans = 0;
        while(low <= high) {
            int mid = (high - low) / 2 + low;
            if(ok(mid, candies, k)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
