// End Sorted
// Problem Code:ENDSORTED

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int pos_of_1, pos_of_n;
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
            if(a[i]==1) {
                pos_of_1 = i;
            }
            if(a[i]==n) {
                pos_of_n = i;
            }
        }
        int ans = pos_of_1+(n-1-pos_of_n);
        if(pos_of_1<pos_of_n) {
            cout << ans << endl;
        }
        else {
            cout << ans-1 << endl;
        }
    }
    return 0;
}
