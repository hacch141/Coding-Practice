// 1637. Widest Vertical Area Between Two Points Containing No Points

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> v;
        for(auto i : points) v.push_back(i[0]);
        sort(v.begin(),v.end());
        int ans = 0;
        for(int i=1; i<v.size(); i++) {
            if(v[i] - v[i-1] > ans) ans = v[i] - v[i-1];
        }
        return ans;
    }
};
