// candy

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        
        int n = ratings.size();
        vector<int> candies(n, 1);

        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        int totalCandies = 0;
        for (int candy : candies) {
            totalCandies += candy;
        }

        return totalCandies;
    }
};
// T : O(N)
// S : O(N)


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++) {
            v.push_back({ratings[i],i});
        }

        sort(v.begin(),v.end());

        vector<int> candy(n,1);
        for(int i=0; i<n; i++) {
            int ind = v[i].second, can = candy[ind];
            if(ind-1 >= 0) {
                if(ratings[ind-1] < ratings[ind]) {
                    can = max(can , candy[ind-1]+1);
                }
            }
            if(ind+1 < n) {
                if(ratings[ind+1] < ratings[ind]) {
                    can = max(can , candy[ind+1]+1);
                }
            }
            candy[ind] = can;
        }

        int ans = 0;
        for(auto i : candy) {
            ans += i;
        }

        return ans;      
    }
};
// T : O(N LogN)
// S : O(N)


//     1 3 3 9 9 7 7 5 7
// 1-> 1 1 1 1 1 1 1 1 1
// 3-> 1 2 1 1 1 1 1 1 1
// 3-> 1 2 1 1 1 1 1 1 1
// 5-> 1 2 1 1 1 1 1 1 1
// 7-> 1 2 1 1 1 1 1 1 1
// 7-> 1 2 1 1 1 1 2 1 1
// 7-> 1 2 1 1 1 1 2 1 2
// 9-> 1 2 1 2 1 1 2 1 2
// 9-> 1 2 1 2 2 1 2 1 2
