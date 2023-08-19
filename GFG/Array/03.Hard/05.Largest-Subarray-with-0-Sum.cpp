// Largest Subarray with 0 Sum

int getLongestZeroSumSubarrayLength(vector<int> &arr){
  	// Write your code here.
  	unordered_map<int,int> mp;
  	mp[0] = 0;
  	int n = arr.size();
  
  	long long sum = 0;
  	int ans = 0;
  
  	for(int i=0; i<n; i++) {
    		sum += arr[i];
    		if(mp.find(sum) != mp.end()) {
    			  ans = max(ans,i-mp[sum]);
    		} 
    		else {
    			  mp[sum] = i;
    		}
  	}
  
  	return ans;
}
// T : O(N)
// S : O(N)


/*
Time Complexity: O(N ^ 2), where 'N' is the length of 'Arr'.

Space Complexity: O(N), where 'N' is the length of 'Arr'.
*/

#include<vector>

int getLongestZeroSumSubarrayLength(vector<int> &arr){
	int n = arr.size();
	int ans = (arr[0] == 0);
	vector<long long> prefix_sum(n);
	prefix_sum[0] = arr[0];
	
	// Calculating the prefix sums.
	for(int i = 1; i < n; ++i){
		prefix_sum[i] = prefix_sum[i - 1] + arr[i];
		
		// Comparing the length of the current subarray starting at 0 and ending at 'i' with the best length found so far.
		if(prefix_sum[i] == 0)
			ans = max(ans, i + 1);
	}
	
	// Iterating over all subarrays.
	for(int i = 1; i < n; ++i){
		for(int j = i; j < n; ++j){
			
			// Comparing the length of the current subarray with the best length found so far.
			if(prefix_sum[j] == prefix_sum[i - 1])
				ans = max(ans, j - i + 1);
		}
	}
	return ans;
}


/*
Time Complexity: O(N ^ 3), where 'N' is the length of 'Arr'.

Space Complexity: O(1)
*/

#include<vector>

int getLongestZeroSumSubarrayLength(vector<int> &arr){
	int ans = 0;
	int n = arr.size();
	
	// Iterating over all subarrays.
	for(int i = 0; i < n; ++i){
		for(int j = i; j < n; ++j){
			long long sum = 0;
			
			// Calculating the sum of the current subarray.
			for(int k = i; k <= j; ++k)
				sum += arr[k];
			
			// Comparing the length of the current subarray and the best length found so far.
			if(sum == 0)
				ans = max(ans, j - i + 1);
		}
	}
	return ans;
}
