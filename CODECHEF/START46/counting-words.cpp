// Counting Words
// Problem Code:CNTWRD

#include <bits/stdc++.h>
using namespace std;

int CNTWRD(int a, int b) {
    return a*b;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        cout<<CNTWRD(a, b)<<endl;
    }
    return 0;
}