#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<long long> vll;

#define speed() ios_base::sync_with_stdio(false), cin.tie(NULL);

int main() {

    speed();

    ll n = 1e8;
    vector<bool> prime(n+1,true);

    for(ll i=2; i*i<=n; i++) {
        if(prime[i]) {
            for(ll j=i*i; j<=n; j+=i) {
                prime[j] = false;
            }
        }
    }

    vll p(1,-1);
    for(ll i=2; i<=n; i++) if(prime[i]) p.push_back(i);

    for(ll i=1; i<p.size(); i+=100) cout << p[i] << endl;

    return 0;
}
