// 514. Freedom Trail

class Solution {
public:

    pair<int,int> leftInd(int curr, string& ring, char& ch) {
        int n = ring.size(), steps = 0;
        curr += n;
        while(ring[curr % n] != ch) {
            curr--;
            steps++;
        }
        return {curr % n, steps + 1};
    }

    pair<int,int> rightInd(int curr, string& ring, char& ch) {
        int n = ring.size(), steps = 0;
        while(ring[curr % n] != ch) {
            curr++;
            steps++;
        }
        return {curr % n, steps + 1};
    }

    int solve(int ind, string& ring, int i, string& key, vector<vector<int>>& dp) {
        if(i == key.size()) return 0;

        if(dp[ind][i] != -1) return dp[ind][i];

        auto itL = leftInd(ind, ring, key[i]);
        auto itR = rightInd(ind, ring, key[i]);
        int l = itL.second + solve(itL.first, ring, i + 1, key, dp);
        int r = itR.second + solve(itR.first, ring, i + 1, key, dp);

        return dp[ind][i] = min(l, r);
    }

    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, ring, 0, key, dp);
    }
};
