// 2115. Find All Possible Recipes from Given Supplies

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string,vector<int>> mp;
        int n = recipes.size();
        for(int i = 0; i < n; i++) {
            for(auto &s : ingredients[i]) {
                mp[s].push_back(i);
            }
        }

        queue<string> q;
        for(auto &s : supplies) q.push(s);

        vector<string> ans;
        vector<int> cnt(n, 0);
        while(!q.empty()) {
            string curr = q.front();
            q.pop();
            for(auto &ind : mp[curr]) {
                cnt[ind]++;
                if(cnt[ind] == ingredients[ind].size()) {
                    q.push(recipes[ind]);
                    ans.push_back(recipes[ind]);
                }
            }
        }

        return ans;
    }
};
