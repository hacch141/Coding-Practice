// Adjacent Sum Parity
// Problem Code:ADJSUMPAR

#include <bits/stdc++.h>
using namespace std;

int firstExpectedPairity(int curr, vector<int> &B, int n) {
    for(int i=0; i<n; i++) {
        if(curr==1 && B[i]==1) {
            curr = 0;
        }
        else if(curr==0 && B[i]==1) {
            curr = 1;
        }
    }
    return curr;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
        int n;
        cin >> n;
        vector<int> B(n);
        for(int i=0; i<n; i++) {
            cin >> B[i];
        }
        int flag = 0;
        int first = 1;
        int firstExpected = firstExpectedPairity(1, B, n);
        if(first == firstExpected) {
            cout << "YES" << endl;
            flag = 1;
        }
        else {
            first = 0;
            firstExpected = firstExpectedPairity(0, B, n);
            if(first == firstExpected) {
                cout << "YES" << endl;
                flag = 1;
            }
        }
        if(!flag) {
            cout << "NO" << endl;
        }
    }
	return 0;
}
