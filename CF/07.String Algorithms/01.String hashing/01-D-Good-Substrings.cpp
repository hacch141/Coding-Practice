#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<long long> vll;
 
#define speed() ios_base::sync_with_stdio(false), cin.tie(NULL);
 
int main() {
 
    speed();
 
    ll k;
    string s, good;
    cin >> s >> good >> k;
 
    vll pow(1501); pow[0] = 1;
    ll mod = 1e15+1;
    for(ll i=1; i<1501; i++) {
        pow[i] = (pow[i-1]*31) % mod;
    }
 
    unordered_set<ll> st;
    ll n = s.length();
    for(ll i=0; i<n; i++) {
        ll bad = 0, h = 0;
        for(ll j=i; j<n; j++) {
            if(good[s[j]-'a'] == '0') bad++;
            if(bad > k) break;
            h = (h + ((s[j] - 'a' + 1) * pow[j-i]) % mod ) % mod;
            st.insert(h);
        }
    }
 
    cout << st.size() << endl;
    
    return 0;
}
