// 1653. Minimum Deletions to Make String Balanced
class Solution {
public:

    int getF(int l, int r, vector<int>& f) {
        if(l > r) return 0;
        int c = f[r];
        if(l > 0) c -= f[l];
        return c;
    }

    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> fa(n, 0), fb(n, 0);
        for(int i = 0; i < n; i++) {
            fa[i] = (s[i] == 'a') + (i > 0 ? fa[i - 1] : 0);
            fb[i] = (s[i] == 'b') + (i > 0 ? fb[i - 1] : 0);
        }

        int ans = INT_MAX;
        for(int i = -1; i < n; i++) {
            ans = min(ans, getF(0, i, fb) + getF(i + 1, n - 1, fa));
        }
        return ans;
    }
};
