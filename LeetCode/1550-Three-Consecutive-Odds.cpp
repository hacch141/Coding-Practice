// 1550. Three Consecutive Odds

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cntOdd = 0;
        for(auto i : arr) {
            if(i % 2 == 1) {
                cntOdd++;
            }
            else {
                cntOdd = 0;
            }
            if(cntOdd == 3) return true;
        }
        return false;
    }
};
