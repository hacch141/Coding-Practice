// 394. Decode String

class Solution {
public:
    string decodeString(string s) {
        stack<string> st, st2;
        int n = s.length();
        string curr = "";
        for(int i = 0; i < n; i++) {
            if(s[i] == '[') {
                st.push(curr);
                curr = "";
            }
            else if(s[i] == ']') {
                string t1 = st.top();
                st.pop();
                string t2 = curr;
                curr = "";
                    
                string num = "";
                while(t1.length() > 0 && t1.back() >= '0' && t1.back() <= '9') {
                    num += t1.back();
                    t1.pop_back();
                }
                reverse(num.begin(),num.end());
                string nw = "";
                for(int i = 0; i < stoi(num); i++) {
                    nw += t2;
                }
                curr += t1;
                curr += nw;
            }
            else {
                curr.push_back(s[i]);
            }
        }
        return curr;
    }
};
