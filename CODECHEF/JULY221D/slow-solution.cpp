// Slow Solution
// Problem Code:SLOWSOLN

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        
        if(c > (a*b)) {
            for(int i=1; i<=a; i++) {
                ans += b*b;
            }
        }
        else {
            for(int i=1; i<=c/b; i++) {
                ans += b*b;
            }
            int rem = c%b;
            ans += rem*rem;
        }
        cout << ans << endl;
    }
    return 0;
}
