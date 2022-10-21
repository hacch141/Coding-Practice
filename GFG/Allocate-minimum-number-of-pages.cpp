//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool helper(int arr[], int N, int pages, int students) {
        int cnt = 0;
        int Allocated = 0;
        for(int i=0; i<N; i++) {
            if(Allocated+arr[i] > pages) {
                cnt++;
                Allocated = arr[i];
                if(Allocated > pages) {
                    return false;
                }
            } else {
                Allocated += arr[i];
            }
        }
        if(cnt < students) {
            return true;
        }
        return false;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M > N) {
            return -1;
        }
        int low = A[0];
        int high = 0;
        for(int i=0; i<N; i++) {
            low = min(low,A[i]);
            high += A[i];
        }
        while(low <= high) {
            int mid = (low+high)/2;
            if(helper(A,N,mid,M)) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
