// 69. Sqrt(x)

class Solution {
public:
    
    int mySqrt(int x) {
        long long low = 0;
        long long high = x;
        long long ans;
        while(low <= high) {
            long long mid = (low+high)/2;
            if(mid*mid == x) {
                return mid;
            }
            if(mid*mid < x) {
                low = mid+1;
                ans = mid;
            }
            else {
                high = mid-1;
            }
        }
        return ans;
    }
};
