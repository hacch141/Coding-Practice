// 1128. Number of Equivalent Domino Pairs

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for(auto &it : dominoes) if(it[0] > it[1]) swap(it[0], it[1]);
        sort(dominoes.begin(), dominoes.end());

        int n = dominoes.size(), ans = 0, cnt = 1;
        for(int i = 1; i < n; i++) {
            if((dominoes[i][0] == dominoes[i - 1][0] && dominoes[i][1] == dominoes[i - 1][1]) || (dominoes[i][0] == dominoes[i - 1][1] && dominoes[i][1] == dominoes[i - 1][0])) {
                cnt++;
            }
            else {
                ans += (cnt * (cnt - 1)) / 2;
                cnt = 1;
            }
        }
        
        ans += (cnt * (cnt - 1)) / 2;
        return ans;
    }
};
