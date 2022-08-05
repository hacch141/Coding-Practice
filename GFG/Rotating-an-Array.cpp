// Rotating an Array

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void leftRotate(int arr[], int n, int d) {
        // code here
        int temp[d];
        for(int i=0; i<d; i++) {
            temp[i] = arr[i];
        }
        for(int j=d; j<n; j++) {
            arr[j-d] = arr[j];
        }
        for(int i=0; i<d; i++) {
            arr[n-d+i] = temp[i];
        }
    }
    
    void leftRotate(int arr[], int n, int d) { //2nd Method with less aux space
        // code here
        reverse(arr, 0, d-1);
        reverse(arr, d, n-1);
        reverse(arr, 0, n-1);
    }
    
    void reverse(int arr[], int low, int high) {
        while(low<high) {
            swap(arr[low],arr[high]);
            low++;
            high--;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> d;
        Solution ob;
        ob.leftRotate(arr, n, d);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}



// } Driver Code Ends
