// Find the element that appears once in sorted array

class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        if(n == 1) return arr[0];
        if(arr[0] != arr[1]) return arr[0];
        if(arr[n-2] != arr[n-1]) return arr[n-1];
        
        int low = 1;
        int high = n - 2;
        while(low <= high) {
            int mid = (high-low)/2 + low;
            
            if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid];
            
            if( (mid%2 == 0 && arr[mid] == arr[mid+1]) || (mid%2 == 1 && arr[mid] == arr[mid-1]) ) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        return -1;
    }
};

// T : O(LogN)
// S : O(1)


class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        int low = 0;
        int high = n-2;
        while(low <= high) {
            int mid = (low+high)/2;
            if(arr[mid] == arr[mid^1]) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return arr[low];
    }
};

// T : O(LogN)
// S : O(1)
