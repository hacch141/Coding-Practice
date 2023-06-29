// Binary Search

// Iterative
class Solution {
    
  public:
    int binarysearch(int arr[], int n, int k) {
        // code here
        int low = 0;
        int high = n-1;
        while(low <= high) {
            int mid = (high-low)/2 + low;
            if(arr[mid]==k) {
                return mid;
            }
            else if(arr[mid] < k) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return -1;
    }
};

// T : O(LogN)
// S : O(1)

// Recursive
class Solution {
  public:
  
    int bs(int low, int high, int arr[], int& k) {
        if(low > high) return -1;
        int mid = (high-low)/2 + low;
        if(arr[mid] == k) {
            return mid;
        }
        if(arr[mid] < k) {
            return bs(mid+1,high,arr,k);
        }
        return bs(low,mid-1,arr,k);
    }
  
    int binarysearch(int arr[], int n, int k) {
        // code here
        return bs(0,n-1,arr,k);
    }
};

// T : O(LogN)
// S : O(LogN) STACK
