// 71. Simplify Path

class Solution {
public:
    string simplifyPath(string path) {

        int n = path.size();
        stack<string> st;

        int ptr = 0;
        while(ptr<n) {
            
            while(ptr<n && path[ptr]=='/') ptr++;

            string s = "";
            while(ptr<n && path[ptr]!='/') {
                s += path[ptr];
                ptr++;
            }

            if(s != "") {
                if(s!=".." && s!=".") {
                    st.push(s);
                }
                else if(s==".." && !st.empty()) {
                    st.pop();
                }
            }

        }

        stack<string> st2;
        while(!st.empty()) {
            st2.push(st.top());
            st.pop();
        }

        string ans = "";
        while(!st2.empty()) {
            ans += '/';
            ans += st2.top();
            st2.pop();
        }
        
        if(ans=="") return "/";
        return ans;
    }
};
