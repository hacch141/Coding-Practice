// Subarrays with equal 1s and 0s

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        for(int i=0; i<n; i++) {
            if(arr[i] == 0) {
                arr[i] = -1;
            }
        }
        
        unordered_map<int,int> mp;
        int pre_fix = 0;
        int cnt = 0;
        
        for(int i=0; i<n; i++) {
            pre_fix += arr[i];
            if(pre_fix == 0) {
                cnt++;
            }
            if(mp[pre_fix]) {
                cnt += mp[pre_fix];
            }
            mp[pre_fix]++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}

// } Driver Code Ends
