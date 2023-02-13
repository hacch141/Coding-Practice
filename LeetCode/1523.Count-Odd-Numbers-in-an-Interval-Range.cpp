// 1523. Count Odd Numbers in an Interval Range

class Solution {
public:
    int countOdds(int low, int high) {
        int odd = 0;
        if(low&1) odd++;
        if(high&1) odd++;
        if(low&1 && high&1) {
            odd += ((high-1) - (low+1))/2;
        }
        else if(low&1) {
            odd += ((high) - (low+1))/2;
        }
        else if(high&1) {
            odd += ((high-1) - (low))/2;
        }
        else {
            odd += (high-low)/2;
        }
        return odd;
    }
};
