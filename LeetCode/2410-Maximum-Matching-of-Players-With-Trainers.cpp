// 2410. Maximum Matching of Players With Trainers

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n1 = players.size(), n2 = trainers.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int ans = 0;
        int p1 = 0, p2 = 0;
        while(p1 < n1 && p2 < n2) {
            if(players[p1] <= trainers[p2]) {
                ans++;
                p1++;
                p2++;
            }
            else {
                p2++;
            }
        }
        return ans;
    }
};
