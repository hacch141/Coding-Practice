// Change Row and Column Both
// Problem Code:CHANGEPOS

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int a = x2-x1;
        int b = y2-y1;
        if(a==0 || b==0) {
            cout << 2 << endl;
        }
        else {
            cout << 1 << endl;
        }
    }
    return 0;
}
