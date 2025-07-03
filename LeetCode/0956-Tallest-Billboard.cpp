// 956. Tallest Billboard

class Solution {
public:
    int solve(int ind, int& n, int diff, vector<int>& rods, vector<map<int,int>>& mp) {
        if(ind >= n) {
            return (diff == 0) ? 0 : INT_MIN;
        }

        if(mp[ind].count(diff)) return mp[ind][diff];

        int left = rods[ind] + solve(ind + 1, n, diff + rods[ind], rods, mp);
        int right = rods[ind] + solve(ind + 1, n, diff - rods[ind], rods, mp);
        int none = solve(ind + 1, n, diff, rods, mp);
        return mp[ind][diff] = max({left, right, none});
    }

    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        vector<map<int,int>> mp(n);
        int ans = solve(0, n, 0, rods, mp) / 2;
        return ans > 0 ? ans : 0;
    }
};
