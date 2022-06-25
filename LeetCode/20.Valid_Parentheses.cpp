// 20. Valid Parentheses

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<char> st;
        bool ans = true;
        int i = 0;
        while(s.length()!=0 && i<s.length()) {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') {
                st.push(s[i]);
            }
            else if(!st.empty() && s[i]==')'){
                if(st.top()!='(') {
                    return false;
                }
                st.pop();
            }
            else if(!st.empty() && s[i]==']'){
                if(st.top()!='[') {
                    return false;
                }
                st.pop();
            }
            else if(!st.empty() && s[i]=='}'){
                if(st.top()!='{') {
                    return false;
                }
                st.pop();
            } else {
                st.push(s[i]);
            }
            i++;
        }
        if(!st.empty()) {
            ans = false;
        }
        return ans;
    }
};

int main() {
    Solution s1;
    cout<<s1.isValid(")")<<endl;
    return 0;
}