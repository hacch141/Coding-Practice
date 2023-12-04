// 2264. Largest 3-Same-Digit Number in String

class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size(), cnt = 1;
        string ans = "";
        for(int i=1; i<n; i++) {
            if(num[i] == num[i-1]) {
                cnt++;
            }
            else {
                if(cnt >= 3 && num.substr(i-3,3) > ans) {
                    ans = num.substr(i-3,3);
                }
                cnt = 1;
            }
        }

        if(cnt >= 3 && num.substr(n-3,3) > ans) {
            ans = num.substr(n-3,3);
        }

        return ans;
    }
};
