// 1625. Lexicographically Smallest String After Applying Operations

class Solution {
    private TreeSet<String> st;

    public void solve(String s, int a, int b) {
        st.add(s);
        StringBuilder op1 = new StringBuilder(s);
        for (int i = 1; i < s.length(); i+=2) {
            char ch = (char)((((op1.charAt(i) - '0') + a) % 10) + '0');
            op1.setCharAt(i, ch);
        }
        String op1Str = op1.toString();
        if (!st.contains(op1Str)) {
            solve(op1Str, a, b);
        }

        String op2 = s.substring(b) + s.substring(0, b);
        if (!st.contains(op2)) {
            solve(op2, a, b);
        }
    }

    public String findLexSmallestString(String s, int a, int b) {
        st = new TreeSet<>();
        solve(s, a, b);
        return st.first();
    }
}
