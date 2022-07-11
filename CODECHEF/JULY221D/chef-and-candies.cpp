// Chef and Candies
// Problem Code:CHEFCAND

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        double a, b;
        cin >> a >> b;
        int ans = 0;
        if(b-a >= 0) {
            cout << 0 << endl;
        }
        else {
            cout << ceil((a-b)/4) << endl;
        }
    }
    return 0;
}
