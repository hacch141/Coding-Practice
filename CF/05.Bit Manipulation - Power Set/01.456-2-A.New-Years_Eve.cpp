// B. New Year's Eve

#include <bits/stdc++.h>
using namespace std;

long long int find_pow(long long num) {
    long long int cnt = 0;
    while(num > 0) {
        cnt++;
        num >>= 1;
    }
    return cnt;
}

int main() {
    long long int n, k, ans;
    cin >> n >> k;
    long long int maxPow = find_pow(n);

    if(k == 1) ans = n;
    else {
        long long int val = 1;
        int power=1;
        for(int i=0; i<maxPow; i++) {
            val *= 2;
        }
        ans = val-1;
    }

    cout << ans << endl;
    return 0;
}
