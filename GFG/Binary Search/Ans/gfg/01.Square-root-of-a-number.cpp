// Square root of a number

class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        int low = 1;
        int high = x;
        long long int ans;
        
        while(low <= high) {
            long long int mid = (high-low)/2 + low;
            
            if(mid*mid <= x) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};

// T : O(LogN)
// S : O(1)
