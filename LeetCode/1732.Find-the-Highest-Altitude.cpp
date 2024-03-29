// 1732. Find the Highest Altitude

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0;
        int ans = 0;
        for(auto i : gain) {
            sum += i;
            ans = max(ans,sum);
        }
        return ans;
    }
};
