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
