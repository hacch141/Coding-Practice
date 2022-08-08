// Longest Sub-Array with Sum K

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<int,int> mp;
        int pre_fix = 0;
        int ans = 0;
        
        for(int i=0; i<N; i++) {
            pre_fix += A[i];
            if(pre_fix == K) {
                ans = i+1;
            }
            if(mp.find(pre_fix) == mp.end()) {
                mp[pre_fix] = i;
            }
            if(mp.find(pre_fix-K) != mp.end()) {
                ans = max(ans,i-mp[pre_fix-K]);
            }
        }
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
