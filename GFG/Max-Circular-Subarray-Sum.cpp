// Max Circular Subarray Sum

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    
    int kedanes(int arr[], int n) {
        int ans = arr[0];
        int maxEnd = arr[0];
        
        for(int i=1; i<n; i++) {
            maxEnd = max(maxEnd+arr[i],arr[i]);
            ans = max(ans,maxEnd);
        }
        return ans;
    }
    
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        int max_normal = kedanes(arr,num);
        if(max_normal<0) {
            return max_normal;
        }
        
        int arr_sum = 0;
        for(int i=0; i<num; i++) {
            arr_sum += arr[i];
            arr[i] = -arr[i];
        }
        
        int max_circular = arr_sum + kedanes(arr,num);
        return max(max_normal,max_circular);
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
