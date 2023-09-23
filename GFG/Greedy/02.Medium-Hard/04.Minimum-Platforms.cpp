// Minimum Platforms

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int i=0, j=0, ans=0;
    	while(j<n) {
    	    while(i<n && arr[i] <= dep[j]) {
    	        i++;
    	    }
    	    ans = max(ans,i-j);
    	    j++;
    	}
    	
    	return ans;
    	
    }
};

// T : O(N LogN)
// S : O(1)
