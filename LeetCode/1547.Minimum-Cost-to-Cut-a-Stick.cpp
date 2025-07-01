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
