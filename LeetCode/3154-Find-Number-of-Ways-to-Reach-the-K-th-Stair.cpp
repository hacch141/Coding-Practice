// 3154. Find Number of Ways to Reach the K-th Stair

class Solution {
public:
    int solve(int stair, int k, int jump, bool can_go_down, map<string, int>& mp) {
        if(stair > k + 1) return 0;

        string key = to_string(stair) + '_' + to_string(jump) + '_' + to_string(can_go_down);
        if(mp.count(key)) return mp[key];

        int up = solve(stair + (1 << jump), k, jump + 1, true, mp);
        int down = 0;
        if(can_go_down && stair > 0) {
            down = solve(stair - 1, k, jump, false, mp);
        }

        return mp[key] = up + down + (stair == k);
    }

    int waysToReachStair(int k) {
        map<string, int> mp;
        return solve(1, k, 0, true, mp);
    }
};

// TC : log K
