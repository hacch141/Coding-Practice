// 2285. Maximum Total Importance of Roads

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        for(auto &it : roads) {
            degree[it[0]]++;
            degree[it[1]]++;
        }

        sort(degree.begin(), degree.end());

        long long ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += 1LL * degree[i - 1] * i;
        }

        return ans;
    }
};
