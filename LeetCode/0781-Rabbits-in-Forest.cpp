// 781. Rabbits in Forest

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
        for(auto &i : answers) mp[i]++;

        int ans = 0;
        for(auto &it : mp) {
            int rabbits_in_one_comb = it.first + 1;
            int num_of_comb = (it.second + rabbits_in_one_comb - 1) / rabbits_in_one_comb;
            ans += num_of_comb * rabbits_in_one_comb;
        }

        return ans;
    }
};
