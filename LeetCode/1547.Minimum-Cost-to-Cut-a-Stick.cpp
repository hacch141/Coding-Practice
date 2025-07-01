// 1547. Minimum Cost to Cut a Stick

class Solution {
public:
    int solve(int l, int r, vector<int>& cuts, unordered_map<int, unordered_map<int,int>>& mp) {
        int cost = INT_MAX;
        if(mp.find(l) != mp.end() && mp[l].find(r) != mp[l].end()) return mp[l][r];
        for(auto c : cuts) {
            if(c > l && c < r) {
                cost = min(cost, r - l + solve(l, c, cuts, mp) + solve(c, r, cuts, mp));
            }
        }
        return mp[l][r] = cost != INT_MAX ? cost : 0;
    }

    int minCost(int n, vector<int>& cuts) {
        unordered_map<int, unordered_map<int,int>> mp;
        return solve(0, n, cuts, mp);
    }
};

// OR

class Solution {Add commentMore actions
private:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k=i; k<=j; k++) {
            int cost = cuts[j+1]-cuts[i-1] + solve(i,k-1,cuts,dp) + solve(k+1,j,cuts,dp);
            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(c+1, vector<int> (c+1,-1));
        return solve(1,c,cuts,dp);
    }
};
