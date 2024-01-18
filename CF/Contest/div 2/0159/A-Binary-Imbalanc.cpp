#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<long long> vll;

#define speed() ios_base::sync_with_stdio(false), cin.tie(NULL);;

string helper(string& s, ll& n) {
    ll count_zeros = 0;
    for(ll i=0; i<n-1; i++) {
        if((s[i]=='0' && s[i+1]=='1') || (s[i]=='1' && s[i+1]=='0')) {
            return "YES";
        }
        if(s[i] == '0') count_zeros++;
    }

    if(s[n-1] == '0') count_zeros++;
    ll count_ones = n - count_zeros;
    if (count_zeros > count_ones) {
        return "YES";
    }

    return "NO";
}

int main() {

    speed();

    ll t;
    cin >> t;

    while(t--) {
        ll n;
        string s;
        cin >> n >> s;
        cout << helper(s,n) << endl;
    }
    return 0;
}
