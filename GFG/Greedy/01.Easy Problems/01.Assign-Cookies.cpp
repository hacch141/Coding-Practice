// Assign Cookies

class Solution {

    public int assignCookie(int[] greed, int[] size) {

        Arrays.sort(greed);
        Arrays.sort(size);

        int i = 0;  // pointer for greed
        int j = 0;  // pointer for cookies
        int ans = 0;

        while (i < greed.length && j < size.length) {

            if (greed[i] <= size[j]) {
                ans++;
                i++;
                j++;
            } 
            else {
                j++;
            }
        }

        return ans;
    }
}

// ======================================================================

#include <bits/stdc++.h>

int assignCookie(vector<int> &greed, vector<int> &size) {
  	// Write your code here.
  	int n = greed.size();
  	int m = size.size();
  
  	sort(greed.begin(),greed.end());
  	sort(size.begin(),size.end());
  
  	int i=0, j=0;
  	int ans = 0;
  	while(i<n && j<m) {
    		if(greed[i] <= size[j]) {
      			ans++;
      			i++;
      			j++;
    		}
    		else {
    			  j++;
    		}
  	}
  
  	return ans;
}
// T : O(N * Log N + M * Log M + N + M)
// S : O(1)
