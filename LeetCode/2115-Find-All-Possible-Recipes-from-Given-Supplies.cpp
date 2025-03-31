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

// Topological Code With Mik
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> st(begin(supplies), end(supplies));

        //adj
        unordered_map<string, vector<int>> adj; //ing ---> recipe


        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++) {
            for(string& ing : ingredients[i]) {
                if(!st.count(ing)) {
                    adj[ing].push_back(i);
                    indegree[i]++;
                }
            }
        }

        queue<int> que;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }

        vector<string> result;
        while(!que.empty()) {
            int i = que.front();
            que.pop();
            string recipe = recipes[i];
            result.push_back(recipe);

            for(int &idx : adj[recipe]) {
                indegree[idx]--;
                if(indegree[idx] == 0) {
                    que.push(idx);
                }
            }
        }

        return result;
    }
};

