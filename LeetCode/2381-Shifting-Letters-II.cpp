// 2381. Shifting Letters II

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> f(n, 0);
        for(auto it : shifts) {
            int l = it[0], r = it[1], dir = it[2];
            if(dir == 1) {
                f[l]++;
                if(r + 1 < n) f[r + 1]--;
            }
            else {
                f[l]--;
                if(r + 1 < n) f[r + 1]++;
            }
        }

        for(int i = 0; i < n; i++) {
            if(i > 0)f[i] += f[i - 1];
            f[i] %= 26;
            if(f[i] < 0)f[i] += 26;
        }

        for(int i = 0; i < n; i++) {
            s[i] = (((s[i] - 'a') + f[i]) % 26) + 'a';
        }
        return s;
    }
};
