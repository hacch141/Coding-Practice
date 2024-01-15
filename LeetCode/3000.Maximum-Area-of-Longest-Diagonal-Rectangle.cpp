// 3000. Maximum Area of Longest Diagonal Rectangle

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0, d = 0;
        for(auto i : dimensions) {
            int l = i[0], w = i[1];
            int curr_d = (l * l) + (w * w);
            if(curr_d >= d) {
                if(curr_d == d) ans = max(ans, l * w);
                else ans = l * w;
                d = curr_d;
            }
        }
        return ans;
    }
};
