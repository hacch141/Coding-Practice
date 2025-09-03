// 3025. Find the Number of Ways to Place People I

class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2) {
        if(v1[1] == v2[1]) return v1[0] < v2[0];
        return v1[1] > v2[1];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        sort(points.begin(), points.end(), cmp);
        for(int i = 0; i < n; i++) {
            int mx = INT_MIN;
            for(int j = i - 1; j >= 0; j--) {
                if(points[j][0] <= points[i][0]) {
                    ans += points[j][0] > mx;
                    mx = max(mx, points[j][0]);
                }
            }
        }
        return ans;
    }
};
