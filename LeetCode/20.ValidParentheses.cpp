// 20. Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        stack<char> st;
        bool ans = true;
        int i = 0;
        
        while(i < s.length()) {
            
            // find any open parentheses then push it to the stack
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') {
                st.push(s[i]);
            }
            
            // find any closing parentheses then compare it with the top element of the satck
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
            } 
            
            else {
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
