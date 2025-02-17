// 1079. Letter Tile Possibilities

class Solution {
public:
    int help(int curr_len, int len, vector<int>& f) {
        if(curr_len == len) return 1;
        int cnt = 0;
        for(int i = 0; i < 26; i++) {
            if(f[i] == 0) continue;
            f[i]--;
            cnt += help(curr_len + 1, len, f);
            f[i]++;
        }
        return cnt;
    }

    int numTilePossibilities(string tiles) {
        int n = tiles.length();
        vector<int> f(26, 0);
        for(auto &ch : tiles) f[ch - 'A']++;
        
        int ans = 0;
        for(int len = 1; len <= n; len++) {
            ans += help(0, len, f);
        }

        return ans;
    }
};
