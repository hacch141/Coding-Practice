// Sort the String
// Problem Code:SRTARR

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, cnt=0;
        char prev = '-';
        cin >> n;
        string s;
        cin >> s;
        for(int i=0; i<n; i++) {
            if(s[i]=='0' && prev=='1') {
                cnt++;
            }
            prev = s[i];
        }
        cout<<cnt<<endl;
    }
    return 0;
}