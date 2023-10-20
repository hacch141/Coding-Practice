// A. Chewbacca and the number

#include <bits/stdc++.h>
using namespace std;

int  main() {
    string s;
    cin >> s;

    int n = s.length();
    int a = s[0] - '0';
    if(a != 9 && a >= 5) {
        s[0] = (9-a) + '0';
    }

    for(int i=1; i<n; i++) {
        a = s[i] - '0';
        if(a >= 5) {
            s[i] = (9-a) + '0';
        }
    }

    cout << s;

    return 0;
}
