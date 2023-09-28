// 921. Minimum Add to Make Parentheses Valid

class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        stack<char> st;

        for(auto i : s) {
            if(i == '(') {
                st.push('(');
            }
            else {
                if(!st.empty() && st.top()=='(') {
                    st.pop();
                }
                else {
                    ans++;
                }
            }
        }

        return ans + st.size();
    }
};



class Solution {
public:
    int minAddToMakeValid(string s) {
        int opens=0,closes=0;
        for(char c:s){
            if(c=='('){
                opens++;
            }else{
                if(opens>0)opens--;
                else closes++;
            }
        }
        return opens+closes;   
    }
};

