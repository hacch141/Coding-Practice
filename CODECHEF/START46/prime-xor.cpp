// Prime Xor
// Problem Code:PRIME_XOR

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int X, Y, Z;
        cin >> X >> Y;
        Z = X^Y;
        int arr[3] = {2, 2, 2};
        
        if(X & 1) {
            arr[0] = 2^X;
        }
        if(Y & 1) {
            arr[1] = 2^Y;
        }
        if(Z & 1) {
            arr[2] = 2^Z;
        }
        sort(arr, arr+3);
        cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
    }
    return 0;
}