// 1395. Count Number of Teams
class Solution {
public:

    int getTeams(vector<int>& rating) {
        int n = rating.size(), ans = 0;

        vector<int> greater(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(rating[j] > rating[i]) greater[i]++;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(rating[j] > rating[i]) ans += greater[j];
            }
        }

        return ans;
    }

    int numTeams(vector<int>& rating) {
        int ans = getTeams(rating);
        reverse(rating.begin(),rating.end());
        ans += getTeams(rating);
        return ans;
    }
};
