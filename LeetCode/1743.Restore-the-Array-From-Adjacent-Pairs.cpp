// 1743. Restore the Array From Adjacent Pairs

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp;
        for (auto i : adjacentPairs) {
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }

        int first, second;
        set<int> vis;
        
        for (auto i : mp) {
            if (i.second.size() == 1) {
                first = i.first;
                second = i.second[0];
                break;
            }
        }

        vector<int> ans;
        ans.push_back(first);
        ans.push_back(second); 
        vis.insert(first);
        vis.insert(second);

        while (ans.size() < adjacentPairs.size()+1) {
            vector<int> v = mp[second];
            int next;

            // Find the next element.
            for (int neighbor : v) {
                if (vis.find(neighbor) == vis.end()) {
                    next = neighbor;
                    break;
                }
            }

            ans.push_back(next);
            vis.insert(next);
            second = next;
        }

        return ans;
    }
};
