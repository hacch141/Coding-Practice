#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
typedef vector<long long> vll;
 
#define speed() ios_base::sync_with_stdio(false), cin.tie(NULL);

ll base1 = 31, base2 = 61, mod1 = (ll)1e9 + 7, mod2 = (ll)1e9 + 9;
vll pw1(1000002), pw2(1000002);

pll getHash(string& s) {
    ll h1 = 0, h2 = 0;
    for(ll i=0; i<s.length(); i++) {
        h1 = (h1 + ((s[i] - 'a' + 1)*pw1[i]) % mod1) % mod1;
        h2 = (h2 + ((s[i] - 'a' + 1)*pw2[i]) % mod2) % mod2;
    }
    return {h1,h2};
}

bool helper(ll ind, ll &n, string& str, string& ans, map<pll,string>& mp) {
    if(ind == n) return true;

    string curr = "";
    ll h1 = 0, h2 = 0;
    for(ll i=ind; i<n; i++) {
        curr += str[i];
        h1 = (h1 + (curr[i-ind] - 'a' + 1)*pw1[i-ind] % mod1) % mod1;
        h2 = (h2 + (curr[i-ind] - 'a' + 1)*pw2[i-ind] % mod2) % mod2;
        pll h = {h1,h2};
        if(mp.find(h) != mp.end()) {
            string prev = ans;
            ans += (mp[h] + ' ');
            if(helper(i+1,n,str,ans,mp)) return true;
            ans = prev;
        }
    }
    return false;
}

void solve() {
    ll n , m;
    string str, s;
    cin >> n >> str >> m;
    
    map<pll,string> mp;
    for(ll i=0; i<m; i++) {
        cin >> s;
        string rev = s;
        for(ll j=0; j<rev.length(); j++) {
            if(rev[j] >= 'A' && rev[j] <= 'Z') {
                rev[j] += ('a' - 'A');
            }
        }
        reverse(rev.begin(),rev.end());
        pll h = getHash(rev);
        mp[h] = s;
    }

    string ans = "";
    helper(0,n,str,ans,mp);
    if(ans.back() == ' ') ans.pop_back();

    cout << ans << endl;
}
 
int main() {
    speed();

    pw1[0] = 1, pw2[0] = 1;
    for(ll i=1; i<1000002; i++) {
        pw1[i] = (pw1[i-1]*base1) % mod1;
        pw2[i] = (pw2[i-1]*base2) % mod2;
    }

    solve();
}
