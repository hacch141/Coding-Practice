// 3027. Find the Number of Ways to Place People II

class Solution {
public:

    static bool cmp(vector<int> a, vector<int> b) {
        if(a[0] == b[0]) return a[1] >= b[1];
        return a[0] < b[0];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int mn, ans = 0, n = points.size();
        for(int i = 0; i < n; i++) {
            mn = 1e9 + 1;
            for(int j = i - 1; j >= 0; j--) {
                if(points[j][1] >= points[i][1] && points[j][1] < mn) {
                    ans++;
                    mn = points[j][1];
                }
            }
        }
        return ans;
    }
};
