// MATH1 Enrolment
// Problem Code:M1ENROL

#include <bits/stdc++.h>
using namespace std;

void M1ENROL(int &a, int &b) {
    if((b-a)>=0) {
        cout<<b-a<<endl;
    }
    else {
        cout<<0<<endl;
    }   
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        M1ENROL(a, b);
    }
    return 0;
}