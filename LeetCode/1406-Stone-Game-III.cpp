// 1406. Stone Game III

class Solution {
public:
    // pair<alice_mx_score,bob_mx_score>
    pair<int,int> solve(int ind, int n, bool alice, vector<int>& stoneValue, unordered_map<int,unordered_map<bool, pair<int,int>>>& mp) {
        if(ind >= n) return {0, 0};

        if(mp.find(ind) != mp.end() && mp[ind].find(alice) != mp[ind].end()) return mp[ind][alice];

        int stone_sum = 0;
        pair<int,int> best = {INT_MIN, INT_MIN};

        for(int i = 0; i < 3; i++) {
            if(ind + i >= n) break;
            stone_sum += stoneValue[ind + i];
            auto curr_p = solve(ind + i + 1, n, !alice, stoneValue, mp);
            if(alice) {
                if(stone_sum + curr_p.first > best.first) {
                    best = {stone_sum + curr_p.first, curr_p.second};
                }
            }
            else {
                if(stone_sum + curr_p.second > best.second) {
                    best = {curr_p.first, stone_sum + curr_p.second};
                }
            }
        }

        return mp[ind][alice] = best;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        unordered_map<int,unordered_map<bool, pair<int,int>>> mp;
        auto p = solve(0, n, true, stoneValue, mp);
        if(p.first > p.second) return "Alice";
        else if(p.first < p.second) return "Bob";
        return "Tie";
    }
};
