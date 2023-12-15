#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
typedef vector<long long> vll;
 
#define speed() ios_base::sync_with_stdio(false), cin.tie(NULL);

void solve() {
    string s;
    cin >> s;
    ll n = s.length();
    vll dp(n,0);
    stack<ll> st;
    ll ans = 0, freq = 1;
    for(ll i=0; i<n; i++) {
        if(s[i] == '(') {
            st.push(i);
        }
        else if(!st.empty()) {
            dp[i] = (i - st.top() + 1);
            if(st.top() > 0) dp[i] += dp[st.top()-1];
            st.pop();
            if(dp[i] > ans) {
                ans = dp[i];
                freq = 1;
            }
            else if(dp[i] == ans) {
                freq++;
            }
        }
    }
    cout << ans << " " << freq << endl;
}
 
int main() {
    speed();
    solve();
}
