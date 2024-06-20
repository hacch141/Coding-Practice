// 1552. Magnetic Force Between Two Balls

class Solution {
public:

    bool ok(vector<int>& position, int m, int mid) {
        int n = position.size(), balls = 1, dst = 0;
        for(int i = 1; i < n; i++) {
            dst += position[i] - position[i - 1];
            if(dst >= mid) {
                balls++;
                dst = 0;
            }
        }
        return balls >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size(), l = 1, h = position[n - 1], ans = 1;
        while(l <= h) {
            int mid = (h - l) / 2 + l;
            if(ok(position, m, mid)) {
                ans = mid;
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        return ans;
    }
};
