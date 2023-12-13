#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
typedef vector<long long> vll;
 
#define speed() ios_base::sync_with_stdio(false), cin.tie(NULL);

ll base1 = 31, base2 = 61, mod1 = (ll)1e9 + 7, mod2 = (ll)1e9 + 9;
vll pw1(600001), pw2(600001);

pll getHash(string& s) {
    ll h1 = 0, h2 = 0;
    for(ll i=0; i<s.length(); i++) {
        h1 = (h1 + ((s[i] - 'a' + 1)*pw1[i]) % mod1) % mod1;
        h2 = (h2 + ((s[i] - 'a' + 1)*pw2[i]) % mod2) % mod2;
    }
    return {h1,h2};
}

void solve() {
    ll n, m;
    cin >> n >> m;
    set<pll> st;

    string s;
    for(ll i=0; i<n; i++) {
        cin >> s;
        st.insert(getHash(s));
    }

    for(ll i=0; i<m; i++) {
        cin >> s;
        pll h = getHash(s);
        for(ll j=0; j<s.length(); j++) {
            char old = s[j];
            for(char ch='a'; ch<'d'; ch++) {
                if(s[j] == ch) continue;
                ll newh1 = (h.first + (((ch - s[j])*pw1[j]) % mod1) + mod1) % mod1;
                ll newh2 = (h.second + (((ch - s[j])*pw2[j]) % mod2) + mod2) % mod2;
                if(st.count({newh1,newh2})) {
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}
 
int main() {
    speed();

    pw1[0] = 1, pw2[0] = 1;
    for(ll i=1; i<600000; i++) {
        pw1[i] = (pw1[i-1]*base1) % mod1;
        pw2[i] = (pw2[i-1]*base2) % mod2;
    }

    solve();
}
