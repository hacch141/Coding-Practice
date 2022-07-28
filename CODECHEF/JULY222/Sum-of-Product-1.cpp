// Sum of Product 1

#include "bits/stdc++.h"
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        vector<int> v(N);
        long cnt = 0;
        long ans = 0;
        for(int i=0; i<N; i++) {
            cin >> v[i];
            if(v[i]==1) {
                cnt++;
                ans += cnt;
            }
            else if(v[i]==0) {
                cnt = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
