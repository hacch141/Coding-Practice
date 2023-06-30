// Capacity To Ship Packages Within D Days

class Solution {
 public:
  
    void find_LH(int arr[], int& N, int& low, int& high) {
        low = INT_MIN;
        high = 0;
        for(int i=0; i<N; i++) {
            low = max(low,arr[i]);
            high += arr[i];
        }
    }
    
    bool isValid(int arr[], int& N, int mid, int& D) {
        int days = 1;
        int w = 0;
        for(int i=0; i<N; i++) {
            if(arr[i] + w > mid) {
                w = arr[i];
                days++;
            }
            else {
                w += arr[i];
            }
        }
        
        return days <= D;
    }
  
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int low, high;
        find_LH(arr,N,low,high);
        int ans = -1;
        
        while(low <= high) {
            int mid = (high-low)/2 + low;
            
            if(isValid(arr,N,mid,D)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};

// T : O(N + N*LogN)
// S : O(1)
