#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<long long> vll;

#define speed() ios_base::sync_with_stdio(false), cin.tie(NULL);

int main() {
    speed();

    ll tc;
    cin >> tc;

    while (tc--) {
        ll n, p, l, t;
        cin >> n >> p >> l >> t;
        ll tasks = ceil(n / 7);

        ll days = 0, one = (2 * t) + l;

        while (p > 0 && tasks > 1) {
            days++;
            p -= one;
            tasks -= 2;
        }

        if(tasks%2 == 0) {
            if(tasks*one/2 > p) {
                cout << ceil(p/one);
            }
        }
        else {

        }

        if (p <= 0)
            cout << n - days << endl;
        else {
            if (tasks) {
                days++;
                p -= (l + t);
            }
            if (p <= 0)
                cout << n - days << endl;
            else {
                days += ceil(p * 1.0 / l);
                cout << max(0LL, n - days) << endl;
            }
        }
    }
    return 0;
}
