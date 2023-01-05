// 452. Minimum Number of Arrows to Burst Balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==1) return 1;
        sort(points.begin(),points.end());
        int n = points.size();
        int start = points[0][0];
        int end = points[0][1];
        int ans = 0;
        for(int i=1; i<n; i++) {
            if(end > points[i][0]) {
                start = points[i][0];
                end =min(end,points[i][1]);
            } else if (end == points[i][0]) {
                continue;
            } else {
                start = points[i][0];
                end = points[i][1];
                ans++;
            }
        }
        ans++;
        return ans;
    }
};
