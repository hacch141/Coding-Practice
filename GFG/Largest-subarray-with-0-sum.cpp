// Largest subarray with 0 sum

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> mp;
        int pre_fix = 0;
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            pre_fix += A[i];
            if(pre_fix == 0) {
                ans = max(ans,i+1);
            }
            if(mp.find(pre_fix) == mp.end()) {
                mp[pre_fix] = i;
            }
            if(mp.find(pre_fix) != mp.end()) {
                ans = max(ans,i-mp[pre_fix]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends
