// Maximum Product Subarray

#include<vector>

int subarrayWithMaxProduct(vector<int> &arr){
	// Write your code here.
  	int n = arr.size();
  	int pref = 1;
  	int suff = 1;
  	int ans = 0;
  	
  	for(int i=0; i<n; i++) {
    		if(pref==0) pref = 1;
    		if(suff==0) suff = 1;
    		pref *= arr[i];
    		suff *= arr[n-1-i];
    		ans = max(ans,max(pref,suff));
  	}
  
  	return ans;
}
// T : O(N)
// S : O(1)

int maxProductSubArray(vector<int>& nums) {
    int result = nums[0];
    for(int i=0;i<nums.size()-1;i++) {
        int p = nums[i];
        for(int j=i+1;j<nums.size();j++) {
           result = max(result,p);
           p *= nums[j];
        }
        result = max(result,p);//manages (n-1)th term 
    }
    return result;
}
// T : O(N^2)
// S : O(1)
