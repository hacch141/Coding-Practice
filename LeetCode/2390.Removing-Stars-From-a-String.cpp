// 2390. Removing Stars From a String

// USING NEW STRING
class Solution {
public:
    string removeStars(string s) {

        string ans = "";
        int n = s.length();

        for(int i=0; i<n; i++) {
            if(s[i]!='*') {
                ans.push_back(s[i]);
            }
            else {
                ans.pop_back();
            }
        }

        return ans;
    }
};


// ===============================================================


// USING POINTER
class Solution {
public:
    string removeStars(string s) {

        string ans = "";
        int n = s.length();

        int ptr = 0;
        for(int i=0; i<n; i++) {
            if(s[i]!='*') {
                s[ptr] = s[i];
                ptr++;
            }
            else {
                ptr--;
            }
        }

        return s.substr(0,ptr);
    }
};


// =================================================================


// USING STACK
class Solution {
public:
    string removeStars(string s) {

        stack<char> st;
        int n = s.length();
        
        for(int i=0; i<n; i++) {
            if(s[i] != '*') st.push(s[i]);
            else if(!st.empty()){
                st.pop();
            }
        }

        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
