// 3019. Number of Changing Keys

class Solution {
public:
    int countKeyChanges(string s) {
        for(auto &c : s) {
            c = tolower(c);
        }
        
        char prev = s[0], ans = 0;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] != prev) {
                ans++;
                prev = s[i];
            }
        }
        
        return ans;
    }
};
