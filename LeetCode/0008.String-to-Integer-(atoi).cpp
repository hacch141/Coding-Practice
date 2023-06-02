// 8. String to Integer (atoi)

class Solution {
public:

    int helper(string s, bool& flag) {
        int ans = 0;
        for(auto i : s) {
            if(flag && ((long long)ans*10 + (i-'0') >= (long long)INT_MAX+1) ) {
                return INT_MIN;
            }
            if(!flag && ((long long)ans*10 + (i-'0') >= INT_MAX) ) {
                return INT_MAX;
            }
            ans = ans*10 + (i-'0');
        }
        return flag ? -ans : ans;
    }

    int myAtoi(string s) {
        int n = s.length();
        string num = "";
        bool flag = false;
        for(int i=0; i<n; i++) {
            if(s[i]==' ') continue;
            else if(i<n && ((s[i]=='-') | s[i]=='+' | (s[i]>='0' && s[i]<='9'))) {
                if(s[i]=='-') {
                    flag = true;
                    i++;
                }
                else if(s[i]=='+') i++;
                while(i<n && s[i]>='0' && s[i]<='9') {
                    num += s[i];
                    i++;
                }
                break;
            }
            return 0;
        }

        return helper(num,flag);
    }
};
