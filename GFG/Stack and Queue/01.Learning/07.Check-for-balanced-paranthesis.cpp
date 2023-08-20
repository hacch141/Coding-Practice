// Check for balanced paranthesis

bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> st;
    for(auto i : s) {
        if(i=='(' || i=='{' || i=='[') {
            st.push(i);
        } 
        else {
            if (st.empty()) {
                return false;
            } 
            else if (i == ')') {
                if (st.top() != '(') return false;
            } else if (i == '}') {
                if(st.top() != '{') return false;
            } else if (i == ']') {
                if(st.top() != '[') return false;
            }
            st.pop();
        }
    }
    return true;
}
// T : O(N)
// S : O(N)
