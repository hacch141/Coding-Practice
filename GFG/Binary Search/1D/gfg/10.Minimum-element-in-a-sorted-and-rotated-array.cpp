// Minimum element in a sorted and rotated array

class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        int low = 0;
        int high = n- 1;
        int ans = INT_MAX;
        
        while(low <= high) {
            int mid = (high-low)/2 + low;
            
            // If low to high is already sorted then we comp first ele and break
            if(arr[low] <= arr[high]) {
                ans = min(ans,arr[low]);
                break;
            }
            else if(arr[low] <= arr[mid]) {
                ans = min(ans,arr[low]);
                low = mid + 1;
            }
            else {
                ans = min(ans,arr[mid]);
                high = mid - 1;
            }
        }
        
        return ans;
    }
};

// T : O(LogN)
// S : O(1)
