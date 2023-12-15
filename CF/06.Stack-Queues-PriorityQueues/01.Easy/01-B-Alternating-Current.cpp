#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
typedef vector<long long> vll;
 
#define speed() ios_base::sync_with_stdio(false), cin.tie(NULL);

ll base1 = 31, base2 = 61, mod1 = (ll)1e9 + 7, mod2 = (ll)1e9 + 9;
vll pw1(1000002), pw2(1000002);

void solve() {
    string s;
    cin >> s;
    stack<char> st;
    for(ll i=0; i<s.length(); i++) {
        if(!st.empty() && st.top() == s[i]) {
            st.pop();
        }
        else {
            st.push(s[i]);
        }
    }
    cout << (st.empty() ? "YES" : "NO") << endl;
}
 
int main() {
    speed();
    solve();
}
