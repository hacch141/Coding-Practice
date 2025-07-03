// 1125. Smallest Sufficient Team

class Solution {
public:
    long long solve(int ind, int m, vector<int>& ppl_skills, int curr_mask, int req_skill_mask, vector<vector<long long>>& dp) {
        if(ind == m) {
            return curr_mask == req_skill_mask ? 0 : -1;
        }

        if(dp[ind][curr_mask] != -2) return dp[ind][curr_mask];

        long long nottake = solve(ind + 1, m, ppl_skills, curr_mask, req_skill_mask, dp);
        long long take = solve(ind + 1, m, ppl_skills, curr_mask | ppl_skills[ind], req_skill_mask, dp);
        if(take != -1) {
            take |= (1LL << ind);
        }

        long long ans = -1;
        if(nottake == -1) {
            ans = take;
        }
        else if(take == -1) {
            ans = nottake;
        }
        else if(__builtin_popcountll(nottake) < __builtin_popcountll(take)) {
            ans = nottake;
        }
        else {
            ans = take;
        }

        return dp[ind][curr_mask] = ans;
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string,int> mp;
        int n = req_skills.size(), m = people.size();
        for(int i = 0; i < n; i++) {
            mp[req_skills[i]] = i;
        }

        vector<int> ppl_skills;
        for(auto v : people) {
            int curr_mask = 0;
            for(auto s : v) {
                if(mp.count(s)) curr_mask |= (1 << mp[s]);
            }
            ppl_skills.push_back(curr_mask);
        }
        
        int req_skill_mask = (1 << n) - 1;
        vector<vector<long long>> dp(m, vector<long long>(req_skill_mask + 1, -2));
        long long ppl_mask = solve(0, m, ppl_skills, 0, req_skill_mask, dp);

        vector<int> ans;
        for(int i = 0; i < m; i++) {
            if((ppl_mask >> i) & 1) ans.push_back(i);
        }
        return ans;
    }
};
