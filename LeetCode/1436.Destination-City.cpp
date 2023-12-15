// 1436. Destination City

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,bool> mp;
        for(auto i : paths) {
            string u = i[0];
            string v = i[1];
            mp[u] = true;
            if(mp.find(v) == mp.end()) {
                mp[v] = false;
            }
        }
        for(auto i : mp) {
            if(i.second == false) return i.first;
        }
        return "";
    }
};
