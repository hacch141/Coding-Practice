// 1900. The Earliest and Latest Rounds Where Players Compete

class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int l = firstPlayer, r = secondPlayer;
        
        if(l == n - r + 1) {
            return {1, 1};
        }

        if(l > n - r + 1) {
            int tmp = n - l + 1;
            l = n - r + 1;
            r = tmp;
        }

        int mx = 1, mn = n;
        int next_round_player_cnt = (n + 1) / 2;
        if(r <= next_round_player_cnt) {
            int cnt_l = l - 1;
            int cnt_m = r - l - 1;
            for(int surv_l = 0; surv_l <= cnt_l; surv_l++) {
                for(int surv_m = 0; surv_m <= cnt_m; surv_m++) {
                    int next_l = surv_l + 1;
                    int next_r = next_l + surv_m + 1;
                    vector<int> res = earliestAndLatest(next_round_player_cnt, next_l, next_r);
                    mn = min(mn, res[0] + 1);
                    mx = max(mx, res[1] + 1);
                }
            }
        }
        else {
            int cnt_l = l - 1;
            int fight_ind = n - r + 1;
            int cnt_m = fight_ind - l - 1;
            int cnt_rem = r - fight_ind - 1;
            for(int surv_l = 0; surv_l <= cnt_l; surv_l++) {
                for(int surv_m = 0; surv_m <= cnt_m; surv_m++) {
                    int next_l = surv_l + 1;
                    int next_r = next_l + surv_m + (cnt_rem + 1) / 2 + 1;
                    vector<int> res = earliestAndLatest(next_round_player_cnt, next_l, next_r);
                    mn = min(mn, res[0] + 1);
                    mx = max(mx, res[1] + 1);
                }
            }
        }

        return {mn, mx};
    }
};
