// 1482. Minimum Number of Days to Make m Bouquets

class Solution {
public:

    bool ok(vector<int>& bloomDay, int m, int k, int mid) {
        int n = bloomDay.size(), bq = 0, cur = 0;
        for(int i = 0; i < n; i++) {
            if(bloomDay[i] <= mid) {
                cur++;
            }
            else {
                cur = 0;
            }

            if(cur == k) {
                bq++;
                cur = 0;
            }
        }
        return bq >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 0, h = 0, ans = -1;
        for(auto i : bloomDay) h = max(h, i);
        while(l <= h) {
            int mid = (h - l) / 2 + l;
            if(ok(bloomDay, m, k, mid)) {
                h = mid - 1;
                ans = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
