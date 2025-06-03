// 1298. Maximum Candies You Can Get from Boxes

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();

        queue<int> q;
        vector<bool> vis(n, false);

        int ans = 0;
        unordered_set<int> extra_boxes;
        for(auto i : initialBoxes) {
            if(status[i]) {
                q.push(i);
                vis[i] = true;
            }
            else {
                extra_boxes.insert(i);
            }
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            ans += candies[u];
            for(auto k : keys[u]) status[k] = 1;

            for(auto v : containedBoxes[u]) {
                if(!vis[v]) {
                    if(status[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                    else {
                        extra_boxes.insert(v);
                    }
                }
            }

            for(auto i : extra_boxes) {
                if(!vis[i] && status[i]) {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }

        return ans;
    }
};
