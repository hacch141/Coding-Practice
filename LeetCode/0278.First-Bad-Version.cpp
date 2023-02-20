// 278. First Bad Version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        while(low<=high) {
            int mid = (high-low)/2 + low;
            if(isBadVersion(mid)) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return low;
    }
};
