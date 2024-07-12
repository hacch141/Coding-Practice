// 1717. Maximum Score From Removing Substrings

class Solution {
public:

    string remove_ab(string s, int x, int& pts, char a, char b) {
        stack<char> st;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] == b && !st.empty() && st.top() == a) {
                st.pop();
                pts += x;
            }
            else {
                st.push(s[i]);
            }
        }

        string tmp;
        while(!st.empty()) {
            tmp.push_back(st.top());
            st.pop();
        }
        reverse(tmp.begin(),tmp.end());
        return tmp;
    }

    int maximumGain(string s, int x, int y) {
        int n = s.length(), pts = 0;
        if(x > y) {
            s = remove_ab(s, x, pts, 'a', 'b');
            s = remove_ab(s, y, pts, 'b', 'a');
        }
        else {
            s = remove_ab(s, y, pts, 'b', 'a');
            s = remove_ab(s, x, pts, 'a', 'b');
        }
        return pts;
    }
};
