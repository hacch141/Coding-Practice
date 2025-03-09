// 3208. Alternating Groups II

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int curr_len = 0, ans = 0, prev = -1;
        for(int i = 0; i < n + k - 1; i++) {
            if(prev == -1 || colors[i % n] != prev) {
                curr_len++;
            }
            else {
                ans += max(0, curr_len - k + 1);
                curr_len = 1;
            }
            prev = colors[i % n];
        }
        ans += max(0, curr_len - k + 1);
        return ans;
    }
};
