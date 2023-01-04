// 2244. Minimum Rounds to Complete All Tasks

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,double> mp;
        for(auto i : tasks) {
            mp[i]++;
        }
        int ans = 0;
        for(auto it : mp) {
            if(it.second == 1) return -1;
            ans += ceil(it.second/3);
        }
        return ans;
    }
};
