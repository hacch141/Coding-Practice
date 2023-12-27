// 1578. Minimum Time to Make Rope Colorful

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int ans = 0;
        for(int i=0; i<n; i++) {
            int maxi = 0;
            while(i<n-1 && colors[i] == colors[i+1]) {
                ans += neededTime[i];
                maxi = max(maxi , neededTime[i]);
                i++;
            }
            ans += neededTime[i];
            maxi = max(maxi , neededTime[i]);
            ans -= maxi;
        }
        return ans;
    }
};
