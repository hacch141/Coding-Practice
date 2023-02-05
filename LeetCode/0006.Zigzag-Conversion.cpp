// 6. Zigzag Conversion

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v(numRows,"");
        int n = s.length();
        if(numRows==1) return s;
        int row = 0;
        bool reverse = false;
        for(int i=0; i<n; i++) {
            v[row] += s[i];
            if(reverse) {
                row--;
            }
            else {
                row++;
            }
            if(row==0 || row==numRows-1) reverse=!reverse;
        }

        string ans = "";
        for(auto it : v) {
            ans += it;
        }
        return ans;
    }
};
