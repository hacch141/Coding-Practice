// Search in Rotated Array 2

class Solution {
  public:
    bool Search(int N, vector<int>& A, int Key) {
        // Code here
        int low = 0;
        int high = N - 1;
        
        while(low <= high) {
            int mid = (high-low)/2 + low;
            if(A[mid] == Key) {
                return true;
            }
            else if(A[low] == A[mid] && A[mid] == A[high]) {
                low++;
                high--;
            }
            else if(A[low] <= A[mid]) {
                if(A[low] <= Key && Key < A[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                if(A[mid] < Key && Key <= A[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        
        return false;
    }
};

// T : O(LogN)
// S : O(1)
