// 633. Sum of Square Numbers

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0, h = sqrt(c);
        while(l <= h) {
            long long val = l * l + h * h;
            if(val == c) return true;
            else if(val < c) l++;
            else h--;
        }
        return false;
    }
};
