// 983. Minimum Cost For Tickets

class Solution {
public:

    int solve(int start, int& n, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if(start == n) return 0;

        if(dp[start]!=-1) return dp[start];
        
        int ptr7=start, ptr30=start;

        while(ptr7<n && days[ptr7] <= days[start]+6) ptr7++;
        while(ptr30<n && days[ptr30] <= days[start]+29) ptr30++;

        int c1=1e9,c2=1e9,c3=1e9;
        c1 = costs[0] + solve(start+1,n,days,costs,dp);
        c2 = costs[1] + solve(ptr7,n,days,costs,dp);
        c3 = costs[2] + solve(ptr30,n,days,costs,dp);

        return dp[start] = min(c1,min(c2,c3));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n,-1);
        return solve(0,n,days,costs,dp);
    }
};
