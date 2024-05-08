// 506. Relative Ranks

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> v = score;
        sort(v.begin(), v.end());
        vector<string> ans(n);
        for(int i = 0; i < n; i++) {
            int rank = n - (lower_bound(v.begin(), v.end(), score[i]) - v.begin());
            if(rank == 1) {
                ans[i] = "Gold Medal";
            }
            else if(rank == 2) {
                ans[i] = "Silver Medal";
            }
            else if(rank == 3) {
                ans[i] = "Bronze Medal";
            }
            else {
                ans[i] = to_string(rank);
            }
        }
        return ans;
    }
};
