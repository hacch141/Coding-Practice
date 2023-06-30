// Rotation

class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int low = 0;
	    int high = n - 1;
	    int mini = INT_MAX;
	    int ind;
	    
	    while(low <= high) {
	        int mid = (high-low)/2 + low;
	        
	        if(arr[low] <= arr[high]) {
	            if(arr[low] < mini) {
	                ind = low;
	                mini = arr[low];
	            }
	            break;
	        }
	        else if(arr[low] <= arr[mid]) {
	            if(arr[low] < mini) {
	                ind = low;
	                mini = arr[low];
	            }
	            low = mid + 1;
	        }
	        else {
	            if(arr[mid] < mini) {
	                ind = mid;
	                mini = arr[mid];
	            }
	            high = mid - 1;
	        }
	    }
	    
	    return ind;
	}
};

// T : O(LogN)
// S : O(1)
