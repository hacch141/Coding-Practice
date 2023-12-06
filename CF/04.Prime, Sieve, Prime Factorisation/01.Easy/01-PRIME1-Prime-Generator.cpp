#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<long long> vll;

#define speed() ios_base::sync_with_stdio(false), cin.tie(NULL);

bool isPrime(ll num) {
    if(num < 2) return false;
    if(num == 2) return true;
    if(num%2 == 0) return false;
    for(ll i=3; i*i<=num; i+=2) {
        if(num%i == 0) return false;
    }
    return true;
}

int main() {

    speed();

    ll t;
    cin >> t;

    while(t--) {
        ll a, b;
        cin >> a >> b;
        for(ll i=a; i<=b; i++) {
            if(isPrime(i)) cout << i << endl;
        }
    }
    return 0;
}
