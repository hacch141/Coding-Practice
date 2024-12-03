// 2109. Adding Spaces to a String

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int n = spaces.size(), ptr = 0;
        for(int i = 0; i < s.length(); i++) {
            if(ptr < n && spaces[ptr] == i) {
                ans.push_back(' ');
                ptr++;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};
