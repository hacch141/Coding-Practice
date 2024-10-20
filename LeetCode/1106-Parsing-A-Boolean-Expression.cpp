// 1106. Parsing A Boolean Expression

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(auto ch : expression) {
            if(ch == ')') {
                bool _or = false, _and = true;
                while(st.top() != '(') {
                    char cur = st.top();
                    st.pop();
                    _or |= (cur == 't');
                    _and &= (cur == 't');
                }
                st.pop();
                char cur = st.top();
                st.pop();
                if(cur == '|') {
                    char tmp = _or ? 't' : 'f';
                    st.push(tmp);
                }
                else if(cur == '&') {
                    char tmp = _and ? 't' : 'f';
                    st.push(tmp);
                }
                else if(cur == '!') {
                    char tmp = _or ? 'f' : 't';
                    st.push(tmp);
                }
            }
            else if(ch == ',') {
                continue;
            }
            else {
                st.push(ch);
            }
        }
        return st.top() == 't' ? true : false;
    }
};
