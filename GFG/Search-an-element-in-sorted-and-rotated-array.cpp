//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}
// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int Search(vector<int> vec, int K) {
    //code here
    int low = 0;
    int high = vec.size()-1;
    while(low <= high) {
        int mid = (low+high)/2;
        if(vec[mid] == K) {
            return mid;
        }
        else if(vec[mid] >= vec[low]) {
            if(K >= vec[low] && K <= vec[mid]) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        else {
            if(K <= vec[high] && K >= vec[mid]) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
    }
    return -1;
}
