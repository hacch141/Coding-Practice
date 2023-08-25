// Kth element of 2 sorted arrays

#include <bits/stdc++.h>

int kthElement(vector<int> &a, vector<int>& b, int n1, int n2, int k){
    // Write your code here
  	int n = n1+n2;
  
  	if(n1 > n2) return kthElement(b,a,n2,n1,k);
  
  	int low = max(0,k-n2);
  	int high = min(n1,k);
  
  	// number of ele on left part
  	int left = k;
  
  	while(low <= high) {
    	int mid1 = (high-low)/2 + low;  // r1 index
    	int mid2 = left - mid1;         // r2 index

    	int l1 = INT_MIN, l2 = INT_MIN;
    	int r1 = INT_MAX, r2 = INT_MAX;
    
    	// left half index
    	if(mid1-1 >= 0) l1 = a[mid1-1];
		if(mid2-1 >= 0) l2 = b[mid2-1];
    
    	// right half index 
    	if(mid1 < n1) r1 = a[mid1];
		if(mid2 < n2) r2 = b[mid2];
    
    	if(l1<=r2 && l2<=r1) {
    		return max(l1,l2);
  		}
    	else if(l1 > r2) {
			high = mid1 - 1;
    	}
    	else if(l2 > r1) {
			  low = mid1 + 1;
    	}
  	}
  	return 0;
}
// T : O(Log min(n1,n2))
// S : O(1)
