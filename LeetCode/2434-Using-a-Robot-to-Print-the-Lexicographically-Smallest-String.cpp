// 2434. Using a Robot to Print the Lexicographically Smallest String

class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();

        vector<int> v(n);
        int mn_ind = n - 1;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] <= s[mn_ind]) mn_ind = i;
            v[i] = mn_ind;
        }

        string ans = "", tmp = "";
        for(int i = 0; i < n; i++) {
            while(!tmp.empty() && tmp.back() <= s[v[i]]) {
                ans += tmp.back();
                tmp.pop_back();
            }
            tmp += s[i];
        }

        reverse(tmp.begin(), tmp.end());
        ans += tmp;

        return ans;
    }
};
