class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	int ans = 1;
    	int platforms = 1;
    	int i = 0;
    	int j = 1;
    	while(i<n && j<n) {
    	    if(arr[j] <= dep[i]) {
    	        platforms++;
    	        j++;
    	    }
    	    else {
    	        platforms--;
    	        i++;
    	    }
    	    ans = max(ans,platforms);
    	}
    	return ans;
    }
};
