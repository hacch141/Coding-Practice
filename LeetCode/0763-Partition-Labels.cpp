// 763. Partition Labels

// Merge Intervals
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        map<char,int> mp;
        for(int i = 0; i < n; i++) {
            mp[s[i]] = i;
        }

        vector<vector<int>> v;
        for(int i = 0; i < n; i++) {
            if(mp.find(s[i]) != mp.end()) {
                v.push_back({i, mp[s[i]]});
                mp.erase(mp.find(s[i]));
            }
        }

        vector<vector<int>> v_merge;
        int st = v[0][0], end = v[0][1];
        for(int i = 1; i < v.size(); i++) {
            if(v[i][0] < end) {
                end = max(end, v[i][1]);
            }
            else {
                v_merge.push_back({st, end});
                st = v[i][0], end = v[i][1];
            }
        }
        v_merge.push_back({st, end});

        vector<int> ans;
        for(auto &it : v_merge) {
            ans.push_back(it[1] - it[0] + 1);
        }

        return ans;
    }
};

// ==================================================

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        map<char,int> mp;
        for(int i = 0; i < n; i++) {
            mp[s[i]] = i;
        }

        vector<int> ans;
        int st = 0, end = mp[s[0]];

        for(int i = 0; i < n; i++) {
            end = max(end, mp[s[i]]);
            if(i == end) {
                ans.push_back(end - st + 1);
                st = i + 1;
            }
        }

        return ans;
    }
};
