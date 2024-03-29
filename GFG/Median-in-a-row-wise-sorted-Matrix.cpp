// Median in a row-wise sorted Matrix

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    int helper(vector<int> &v, int val) {
        int l = 0;
        int h = v.size() - 1;
        while(l <= h) {
            int mid = (l+h)/2;
            if(v[mid] <= val) {
                l = mid+1;
            }
            else {
                h = mid-1;
            }
        }
        return l;
    }

    int median(vector<vector<int>> &matrix, int r, int c){
        // code here  
        int low = 1;
        int high = 2000;
        int n = r;
        int m = c;
        while(low <= high) {
            int mid = (low+high)/2;
            int cnt = 0;
            for(int i=0; i<n; i++) {
                cnt += helper(matrix[i],mid);
            }
            if(cnt <= (n*m)/2) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends
