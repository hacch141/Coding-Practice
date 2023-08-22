// Maximal Rectangles

#include <bits/stdc++.h>

int largestRectangale(vector<int>& arr, int n) {
  	vector<int> next(n), prev(n);
  	stack<int> st1, st2;
  
  	for(int i=0; i<n; i++) {
    		prev[i] = i;
    		next[i] = n-1-i;
  	}
  
  	// finding next smaller
  	for(int i=0; i<n; i++) {
    		while(!st1.empty() && arr[i] < arr[st1.top()]) {
      			next[st1.top()] = i - st1.top() - 1;
      			st1.pop();
    		}
    		st1.push(i);
  	}
  
  	// finding prev smaller
  	for(int i=n-1; i>=0; i--) {
    		while(!st2.empty() && arr[i] <= arr[st2.top()]) {
      			prev[st2.top()] = st2.top() - i - 1;
      			st2.pop();
    		}
    		st2.push(i);
  	}
  
  	int ans = 0;
  	for(int i=0; i<n; i++) {
    		int area = arr[i] * (1 + prev[i] + next[i]);
    		ans = max(ans,area);
  	}
  
  	return ans;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
  	// Write your code here.
  	for(int i=1; i<n; i++) {
    		for(int j=0; j<m; j++) {
      			if(mat[i][j] != 0){
      				  mat[i][j] += mat[i-1][j];
      			}
    		}
  	}
  
  	int ans = 0;
  	for(int i=0; i<n; i++) {
  		  ans = max(ans,largestRectangale(mat[i],m));
  	}
  
  	return ans;
}

// T : O(N*M)
// S : O(N)
