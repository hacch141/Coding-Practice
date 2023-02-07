// 1626. Best Team With No Conflicts


// Memoization
class Solution {

private:
    void pairsort(vector<int>& a, vector<int>& b, int n) {
        pair<int,int> pairt[n];
        for (int i = 0; i < n; i++) {
            pairt[i].first = a[i];
            pairt[i].second = b[i];
        }
        sort(pairt, pairt + n);
        for (int i = 0; i < n; i++) {
            a[i] = pairt[i].first;
            b[i] = pairt[i].second;
        }
    }


    int solve(int i, int n, vector<int>& scores, vector<int>& ages, int prev, vector<vector<int>>& dp) {
        if(i==n) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int notpick = 0 + solve(i+1,n,scores,ages,prev,dp);
        int pick = INT_MIN;
        if(prev==-1 || (ages[i]==ages[prev]) || (ages[i]>ages[prev] && scores[i]>=scores[prev])) {
            pick = scores[i] + solve(i+1,n,scores,ages,i,dp);
        }
        return dp[i][prev+1] = max(pick,notpick);
    }

public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        pairsort(ages,scores,n);
        vector<vector<int>> dp(n, vector<int> (n+1,-1));
        return solve(0,n,scores,ages,-1,dp);
    }
};



// Tabulation
class Solution {

private:
    void pairsort(vector<int>& a, vector<int>& b, int n) {
        pair<int,int> pairt[n];
        for (int i = 0; i < n; i++) {
            pairt[i].first = a[i];
            pairt[i].second = b[i];
        }
        sort(pairt, pairt + n);
        for (int i = 0; i < n; i++) {
            a[i] = pairt[i].first;
            b[i] = pairt[i].second;
        }
    }

public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        pairsort(ages,scores,n);
        vector<vector<int>> dp(n+1, vector<int> (n+1,0));

        for(int i=n-1; i>=0; i--) {
            for(int prev=i-1; prev>=-1; prev--) {
                int notpick = 0 + dp[i+1][prev+1];
                int pick = INT_MIN;
                if(prev==-1 || (ages[i]==ages[prev]) || (ages[i]>ages[prev]&&scores[i]>=scores[prev])) {
                    pick = scores[i] +dp[i+1][i+1];
                }
                dp[i][prev+1] = max(pick,notpick);
            }
        }
        return dp[0][0];
    }
};



// space optimization
class Solution {

private:
    void pairsort(vector<int>& a, vector<int>& b, int n) {
        pair<int,int> pairt[n];
        for (int i = 0; i < n; i++) {
            pairt[i].first = a[i];
            pairt[i].second = b[i];
        }
        sort(pairt, pairt + n);
        for (int i = 0; i < n; i++) {
            a[i] = pairt[i].first;
            b[i] = pairt[i].second;
        }
    }

public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        pairsort(ages,scores,n);
        vector<int> dp(n+1,0), curr(n+1,0);

        for(int i=n-1; i>=0; i--) {
            for(int prev=i-1; prev>=-1; prev--) {
                int notpick = 0 + dp[prev+1];
                int pick = INT_MIN;
                if(prev==-1 || (ages[i]==ages[prev]) || (ages[i]>ages[prev]&&scores[i]>=scores[prev])) {
                    pick = scores[i] +dp[i+1];
                }
                curr[prev+1] = max(pick,notpick);
            }
            dp = curr;
        }
        return dp[0];
    }
};
