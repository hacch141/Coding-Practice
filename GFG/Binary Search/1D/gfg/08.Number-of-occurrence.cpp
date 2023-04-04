class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
	bool isValid(int arr[], int n, int x) {
	    
	    int low = 0;
	    int high = n-1;
	    
	    while(low<=high) {
	        
	        int mid = (high-low)/2 + low;
	        
	        if(arr[mid] == x) {
	            return true;
	        }
	        
	        else if(arr[mid] < x) {
	            low = mid+1;
	        }
	        
	        else {
	            high = mid-1;
	        }
	        
	    }
	    return false;
	}
	
		
	int count(int arr[], int n, int x) {
	    // code here
	    
	    bool flag = isValid(arr,n,x);
	    if(!flag) return 0;
	    
	    int start = lower_bound(arr, arr+n, x) - arr;
	    int end = upper_bound(arr, arr+n, x) - arr;
	    
	    return end-start;
	}
};
