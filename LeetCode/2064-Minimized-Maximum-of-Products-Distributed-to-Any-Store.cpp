// 2064. Minimized Maximum of Products Distributed to Any Store

class Solution {
public:
    bool ok(int mid, int& n, vector<int>& quantities) {
        int cnt = 0;
        for(auto i : quantities) {
            cnt += (i + mid - 1) / mid;
        }
        return cnt <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = *max_element(quantities.begin(), quantities.end()), ans = high;
        while(low <= high) {
            int mid = (high - low) / 2 + low;
            if(ok(mid, n, quantities)) {
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
