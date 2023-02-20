// 374. Guess Number Higher or Lower

class Solution {
public:
    int guessNumber(int n) {
        int low = 0;
        int high = n;
        while(low<=high) {
            int mid =  (high-low)/2 + low;
            if(guess(mid) == 0) {
                return mid;
            }
            else if(guess(mid) == -1) {
                high = mid-1;
            }
            else if(guess(mid) == 1) {
                low = mid+1;
            }
        }
        return 0;
    }
};
