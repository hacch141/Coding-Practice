// 1431. Kids With the Greatest Number of Candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxi = INT_MIN;

        for(auto i : candies) {
            maxi = max(maxi,i);
        }

        for(auto i : candies) {
            if(i+extraCandies >= maxi) {
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }
        
        return ans;
    }
};
