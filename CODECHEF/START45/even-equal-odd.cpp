// Even Equal Odd
// Problem Code:EVEQODD

#include <bits/stdc++.h>
using namespace std;

int evenToOdd(int x) {
    int ans = 0;
    while(x%2 == 0) {
        ans++;
        x /= 2;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(2*n);
        int odd=0, even=0;
        vector<int> evenMoves;
        for(int i=0; i<2*n; i++) {
            cin >> a[i];
            if(a[i]%2==0) {
                even++;
                evenMoves.push_back(evenToOdd(a[i]));
            }
            else {
                odd++;
            }
        }
        sort(evenMoves.begin(), evenMoves.end());
        if(odd>=n) {
            cout << odd-n << endl;
        }
        else {
            int evenm = 0;
            for(int i=0; i<even-n; i++) {
                evenm += evenMoves[i];
            }
            cout << evenm << endl;
        }
    }
    return 0;
}
