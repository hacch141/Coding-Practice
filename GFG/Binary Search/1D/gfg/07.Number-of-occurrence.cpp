// Number of occurrence

class Solution{
public:	
	int find_first(int arr[], int n, int x) {
	    int low = 0;
	    int high = n - 1;
	    int first = -1;
	    
	    while(low <= high) {
	        int mid = (high-low)/2 + low;
	        if(arr[mid] == x) {
	            first = mid;
	            high = mid - 1;
	        }
	        else if(arr[mid] < x) {
	            low = mid + 1;
	        }
	        else {
	            high = mid - 1;
	        }
	    }
	    return first;
	}
	
	int find_last(int arr[], int n, int x) {
	    int low = 0;
	    int high = n - 1;
	    int last = -1;
	    
	    while(low <= high) {
	        int mid = (high-low)/2 + low;
	        if(arr[mid] == x) {
	            last = mid;
	            low = mid + 1;
	        }
	        else if(arr[mid] < x) {
	            low = mid + 1;
	        }
	        else {
	            high = mid - 1;
	        }
	    }
	    return last;
	}
		
	int count(int arr[], int n, int x) {
	    // code here
	    int first = find_first(arr,n,x);
	    int last = find_last(arr,n,x);
	    return first != -1 ? last - first + 1 : 0;
	}
};

// T : O(LogN)
// S : O(1)


// Use upper bound and lower bound
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

