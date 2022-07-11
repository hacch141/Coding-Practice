// Journey of the Knight
// Problem Code:KNIGHT2

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(((x1-y1)%2==0 && (x2-y2)%2==0) || ((x1-y1)%2!=0 && (x2-y2)%2!=0)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" <<endl;
        }
    }
    return 0;
}
