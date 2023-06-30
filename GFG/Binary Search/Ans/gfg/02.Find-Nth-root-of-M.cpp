// Find Nth root of M

class Solution{
	public:
	
	int powN(int n, int mid, int m) {
	    long long ans = 1;
	    for(int i=0; i<n; i++) {
	        ans = ans * mid;
	        if(ans > m) return -1;
	    }
	    if(ans == m) return 1;
	    return 0;
	}
	
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int low = 1;
	    int high = m;
	    
	    while(low <= high) {
	        int mid = (high-low)/2 + low;
        
	        int curr = powN(n,mid,m);
	        
	        if(curr == 1) {
	            return mid;
	        }
	        else if(curr == -1) {
	            high = mid - 1;
	        }
	        else if(curr == 0){
	            low = mid + 1;
	        }
	    }
	    
	    return -1;
	}  
};

// T : O(LogN)
// S : O(1)
