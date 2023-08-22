// Largest rectangle in a histogram

 #include <bits/stdc++.h>
 
 int largestRectangle(vector < int > & heights) {
   // Write your code here.
     int n = heights.size();
     vector<int> next(n), prev(n);    
     stack<int> st1,st2;
     
     for(int i=0; i<n; i++) {
         next[i] = n-1-i;
         prev[i] = i;
     }
  
     // finding next smaller
     for(int i=0; i<n; i++) {
         while(!st1.empty() && heights[i] < heights[st1.top()]) {
             next[st1.top()] = i - st1.top() - 1;
             st1.pop();
         }
         st1.push(i);
     }
  
     for(int i=n-1; i>=0; i--) {
         while(!st2.empty() && heights[i] <= heights[st2.top()]) {
             prev[st2.top()] = st2.top() - i - 1;
             st2.pop();
         }
         st2.push(i);
     }
  
     int ans = 0;
     for(int i=0; i<n; i++) {
         int area = heights[i] * (1 + prev[i] + next[i]);
         ans = max(ans,area);
     }
  
     return ans;
 }

// T : O(N)
// S : O(N)
