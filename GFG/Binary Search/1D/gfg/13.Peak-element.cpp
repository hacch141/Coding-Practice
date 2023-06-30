// Peak element

class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
       if(n == 1) return 0;
       if(arr[0] >= arr[1]) return 0;
       if(arr[n-1] >= arr[n-2]) return n-1;
       
       int low = 1;
       int high = n - 2;
       
       while(low <= high) {
            int mid = (high-low)/2 + low;
            if(arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1]) {
                return mid;
            }
            else if(arr[mid] > arr[mid-1]) {
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
       }
       return -1;
    }
};

// T : (LogN)
// S : O(1)
