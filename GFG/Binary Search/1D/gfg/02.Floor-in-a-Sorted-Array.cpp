// Floor in a Sorted Array

class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        long long low = 0;
        long long high = n-1;
        int floor = -1;
        
        while(low<=high) {
            long long mid = (high-low)/2 + low;
            if(x == v[mid]) {
                return (int)mid;
            }
            else if(x > v[mid]) {
                floor = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
            
        }
        return floor;
    }
};

// T : O(LogN)
// S : O(1)



// STRIVER 
// Lower Bound
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}
