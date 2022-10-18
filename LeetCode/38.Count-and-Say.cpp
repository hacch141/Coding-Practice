// 38. Count and Say

class Solution {
public:
    
    string helper(string s) {
        string ans = "";
        int cnt = 1;
        int i;
        for(i=0; i<s.length()-1; i++) {
            if(s[i] == s[i+1]) {
                cnt++;
            }else {
                ans += cnt+'0';
                ans += s[i];
                cnt = 1;
            }
        }
        ans += cnt+'0';
        ans += s[i];
        return ans;
    }
    
    string countAndSay(int n) {
        if(n == 1) {
            return "1";
        }
        string ans = "1";
        for(int i=0; i<n-1; i++) {
            ans = helper(ans);
        }
        return ans;
    }
};
