// 2594. Minimum Time to Repair Cars

class Solution {
public:
    bool ok(long long mid, vector<int>& ranks, int cars) {
        long long cnt = 0;
        for(auto &r : ranks) {
            cnt += sqrt(mid / r);
        }
        return cnt >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 0, high = 1e14, ans;
        while(low <= high) {
            long long mid = (high - low) / 2 + low;
            if(ok(mid, ranks, cars)) {
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
