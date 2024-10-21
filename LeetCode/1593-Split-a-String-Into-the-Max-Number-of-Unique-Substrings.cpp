// 1593. Split a String Into the Max Number of Unique Substrings

class Solution {
public:
    int maxUniqueSplit(string s) {
        int n = s.length(), ans = 0;
        for(int mask = 0; mask < (1 << n); mask++) {
            string cur = "";
            set<string> st;
            bool f = true;
            for(int i = 0; i < n; i++) {
                cur += s[i];
                if((mask >> i) & 1) {
                    if(st.count(cur)) {
                        f = false;
                        break;
                    }
                    else {
                        st.insert(cur);
                        cur = "";
                    }
                }
            }
            if(f) ans = max(ans, (int)st.size());
        }
        return ans;
    }
};
