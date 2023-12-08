#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<long long> vll;
 
#define speed() ios_base::sync_with_stdio(false), cin.tie(NULL);

ll mod = (ll)1e9 + 7;
vll deg(5001), p(5002,0), s(5002,0);

ll pref(ll l , ll r) {
    return ((p[r] - (p[l-1]*deg[r-l+1]) % mod) + mod) % mod;
}

ll suff(ll l , ll r) {
    return ((s[l] - (s[r+1]*deg[r-l+1]) % mod) + mod) % mod;
}

string solve(string& str) {
    ll n = str.length();
        
    for(ll i=1; i<=n; i++) p[i] = (p[i-1]*31 + (str[i-1] - 'a' + 1)) % mod;
    s[n+1] = 0;
    for(ll i=n; i>=1; i--) s[i] = (s[i+1]*31 + (str[i-1] - 'a' + 1)) % mod;

    ll ptr = 0;
    for(ll i=1; i<=(n+1)/2; i++) {
        if(pref(1,i) == suff(n+1-i,n)) {
            ptr = i;
        }
    }

    if(ptr == (n+1)/2) return str;

    string ls = "", rs = "";
    for(ll i=ptr+1; i<=n-ptr; i++) if(pref(ptr+1,i) == suff(ptr+1,i)) ls = str.substr(ptr,i-ptr);
    for(ll i=n-ptr; i>=ptr+1; i--) if(pref(i,n-ptr) == suff(i,n-ptr)) rs = str.substr(i-1,n-ptr-i+1);

    string ans = str.substr(0,ptr) + (ls.length() >= rs.length() ? ls : rs) + str.substr(n-ptr,ptr);
    return ans;
}
 
int main() {
 
    speed();
 
    ll t;
    cin >> t;

    deg[0] = 1;
    for(ll i=1; i<5001; i++) {
        deg[i] = (deg[i-1] * 31) % mod;
    }

    while(t--) {
        string str;
        cin >> str;
        cout << solve(str) << endl;
    }
    return 0;
}
