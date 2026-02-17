// Check for balanced paranthesis

class Solution {

    public boolean isValidParenthesis(String s) {

        Stack<Character> st = new Stack<>();

        for (char ch : s.toCharArray()) {

            // Opening brackets
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            else {

                if (st.isEmpty()) {
                    return false;
                }

                char top = st.peek();

                if (ch == ')' && top != '(') return false;
                if (ch == '}' && top != '{') return false;
                if (ch == ']' && top != '[') return false;

                st.pop();
            }
        }

        // Important: stack must be empty
        return st.isEmpty();
    }
}

// =========================================================================

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
