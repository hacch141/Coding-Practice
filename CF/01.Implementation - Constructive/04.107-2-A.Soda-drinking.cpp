// A. Soda drinking

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n , k , l , c , d , p , nl , np;
    cin >> n;
    cin >> k;
    cin >> l;
    cin >> c;
    cin >> d;
    cin >> p;
    cin >> nl;
    cin >> np;

    cout << min((k*l)/nl , min(c*d , p/np))/n ;

    return 0;
}
