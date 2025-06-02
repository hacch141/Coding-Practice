// 135. Candy

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<vector<int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({ratings[i], i});
        }
        sort(v.begin(), v.end());

        vector<int> candy(n, 1);
        for(int i = 0; i < n; i++) {
            int rating = v[i][0], ind = v[i][1], c = candy[ind];
            if(ind - 1 >= 0 && ratings[ind] > ratings[ind - 1]) {
                c = max(c, candy[ind - 1] + 1);
            }
            if(ind + 1 < n && ratings[ind] > ratings[ind + 1]) {
                c = max(c, candy[ind + 1] + 1);
            }
            candy[ind] = c;
        }

        int ans = 0;
        for(auto i : candy) ans += i;

        return ans;
    }
};
