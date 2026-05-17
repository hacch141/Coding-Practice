// Parsing A Boolean Expression

class Solution {
    public boolean parseBoolExpr(String expression) {
        Stack<Character> st = new Stack<>();

        for (char ch : expression.toCharArray()) {
            if (ch == ')') {
                boolean and = true, or = false;
                while (st.peek() != '(') {
                    if (st.pop() == 't') {
                        or = true;
                    }
                    else {
                        and = false;
                    }
                }
                st.pop();
                char op = st.pop();
                if (op == '&') {
                    if (and) st.push('t');
                    else st.push('f');
                }
                else if (op == '|') {
                    if (or) st.push('t');
                    else st.push('f');
                }
                else {
                    if (!and) st.push('t');
                    else st.push('f');
                }
            }
            else if (ch != ',') {
                st.push(ch);
            }
        }

        return st.pop() == 't' ? true : false;
    }
}
