// 1051. Height Checker

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> c(101, 0);
        for(auto i : heights) c[i]++;
        int n = heights.size(), st = 1, ans = 0;
        for(int i = 0; i < n; i++) {
            while(c[st] == 0) st++;
            ans += st != heights[i];
            c[st]--;
        }
        return ans;
    }
};
