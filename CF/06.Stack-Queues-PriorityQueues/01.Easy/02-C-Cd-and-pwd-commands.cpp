#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
typedef vector<long long> vll;
 
#define speed() ios_base::sync_with_stdio(false), cin.tie(NULL);

void solve() {
    ll n;
    cin >> n;
    
    string pwd = "/";
    for(ll i=0; i<n; i++) {
        string s;
        cin >> s;
        if(s == "pwd") {
            cout << pwd << endl;
        }
        else {
            string p;
            cin >> p;
            if(p[0] == '/') {
                pwd = "/";
            }
            stringstream ss(p);
            string token;
            while(getline(ss,token,'/')) {
                if(token == "..") {
                    if(pwd.length() > 1) {
                        pwd.pop_back();
                        while(pwd.back() != '/') pwd.pop_back();
                    }
                }
                else if(token != "") {
                    pwd += (token + '/');
                }
            }
        }
    }
}
 
int main() {
    speed();
    solve();
}






#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
typedef vector<long long> vll;
 
#define speed() ios_base::sync_with_stdio(false), cin.tie(NULL);

ll base1 = 31, base2 = 61, mod1 = (ll)1e9 + 7, mod2 = (ll)1e9 + 9;
vll pw1(1000002), pw2(1000002);

void solve() {
    ll n;
    cin >> n;
    
    vector<string> pwd;
    for(ll i=0; i<n; i++) {
        string s;
        cin >> s;
        if(s == "pwd") {
            cout << '/';
            if(pwd.size() > 0) {
                for(auto i : pwd) {
                    cout << i << '/';
                }
            }
            cout << endl;
        }
        else {
            string p;
            cin >> p;
            if(p[0] == '/') {
                pwd.clear();
            }
            stringstream ss(p);
            string token;
            while(getline(ss,token,'/')) {
                if(token == "..") {
                    if(pwd.size() > 0) {
                        pwd.pop_back();
                    }
                }
                else if(token != "") {
                    pwd.push_back(token);
                }
            }
        }
    }
}
 
int main() {
    speed();
    solve();
}
