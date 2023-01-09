class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it : tokens) {
            if(it == "+" || it == "-" || it == "*" || it == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if(it == "+") st.push(a+b);
                else if(it == "-") st.push(a-b);
                else if(it == "*") st.push(a*b);
                else if(it == "/") st.push(a/b);
            }
            else {
                int num = 0;
                bool flag = false;
                for(int i=0; i<it.length(); i++) {
                    if(it[i]=='-') {
                        flag = true;
                        continue;
                    }
                    num = (num*10) + (it[i]-'0');
                }
                if(flag) {
                    st.push(-num);
                }
                else st.push(num);
            }
        }
        return st.top();
    }
};
