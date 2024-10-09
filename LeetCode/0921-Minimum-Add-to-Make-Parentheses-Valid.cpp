// 921. Minimum Add to Make Parentheses Valid

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans = 0, open = 0;
        for(auto ch : s) {
            if(ch == '(') {
                open++;
            }
            else if(open > 0) {
                open--;
            }
            else {
                ans++;
            }
        }
        return ans + open;
    }
};
