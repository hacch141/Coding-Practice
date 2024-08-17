// 1937. Maximum Number of Points with Cost
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();

        vector<long long> prev(m);
        for(int i = 0; i < m; i++) prev[i] = (long long)points[0][i];

        long long ans = 0;
        for(int i = 1; i < n; i++) {
            vector<long long> curr(m, 0);
            for(long j = 0; j < m; j++) {
                for(int k = 0; k < m; k++) {
                    curr[j] = max(curr[j], points[i][j] + prev[k] - abs(j - k));
                }
            }
            prev = curr;
        }

        for(int i = 0; i < m; i++) ans = max(ans, prev[i]);
        
        return ans;
    }
};
// TC : (n * m * m)


// Optimised
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();

        vector<long long> prev(m);
        for(int i = 0; i < m; i++) prev[i] = (long long)points[0][i];

        long long ans = 0;
        for(int i = 1; i < n; i++) {
            vector<long long> curr(m, 0), leftMax(m, 0), rightMax(m, 0);

            leftMax[0] = prev[0];
            for(int j = 1; j < m; j++) {
                leftMax[j] = max(leftMax[j - 1] - 1 , prev[j]);
            }

            rightMax[m - 1] = prev[m - 1];
            for(int j = m - 2; j >= 0; j--) {
                rightMax[j] = max(rightMax[j + 1] - 1 , prev[j]);
            }

            for(long j = 0; j < m; j++) {
                curr[j] = points[i][j] + max(leftMax[j], rightMax[j]);
            }
            prev = curr;
        }

        for(int i = 0; i < m; i++) ans = max(ans, prev[i]);

        return ans;
    }
};
// TC : (n * m)


