// 1266. Minimum Time Visiting All Points

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i=1; i<points.size(); i++) {
            int x1 = points[i-1][0], y1 = points[i-1][1];
            int x2 = points[i][0], y2 = points[i][1];

            x2 = abs(x2-x1);
            y2 = abs(y2-y1);

            ans += max(x2,y2);
        }

        return ans;
    }
};
