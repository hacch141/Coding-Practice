// To Divide or Not To Divide

#include "bits/stdc++.h"
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int A, B, N;
        cin >> A >> B >> N;
        if(A%B==0) {
            cout << "-1" << endl;
            continue;
        }
        int a = N;
        if(a%A!=0) {
            a = N+A-(N%A);
        }
        while(!(a%A==0 && a%B!=0)) {
            a += A;
        }
        cout << a << endl;
    }
    return 0;
}
