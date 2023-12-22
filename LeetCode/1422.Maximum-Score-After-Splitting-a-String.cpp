// 1422. Maximum Score After Splitting a String

class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = 0, ans = 0, n = s.length();

        for(int i=0; i<s.length(); i++) {
            if(s[i] == '1') ones++;
        }
        
        for(int i=0; i<s.length()-1; i++) {
            if(s[i] == '0') zeros++;
            else if(s[i] == '1') ones--;
            ans = max(ans , zeros + ones);
        }

        return ans;
    }
};
