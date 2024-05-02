// 763. Partition Labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        for(int i=0; i<s.length(); i++) {
            mp[s[i]] = i;
        }
        
        int prev = -1;
        int maximum = 0;
        vector<int> ans;
        
        for(int i=0; i<s.length(); i++) {
            maximum = max(maximum,mp[s[i]]);
            if(i == maximum) {
                ans.push_back(maximum-prev);
                prev = maximum;
            }
        }
        return ans;
    }
};


class Solution {
public:

    int help(map<char,int>& mp, map<char,int>& mp2) {
        int cnt = 0;
        for(auto i : mp2) {
            char ch = i.first;
            int f = i.second;
            if(mp[ch] != f) return -1;
            cnt += f;
        }
        return cnt;
    }

    vector<int> partitionLabels(string s) {
        map<char,int> mp, mp2;
        for(auto ch : s) mp[ch]++;
        int n = s.length();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            mp2[s[i]]++;
            int curr = help(mp, mp2);
            if(curr != -1) {
                ans.push_back(curr);
                mp2.clear();
            }
        }
        return ans;
    }
};
