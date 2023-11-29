#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long nb, ns, nc;
    cin >> nb >> ns >> nc;
    long long pb, ps, pc;
    cin >> pb >> ps >> pc;
    long long r;
    cin >> r;

    vector<int> burger(3, 0);
    for (auto ch : s) {
        if (ch == 'B') burger[0]++;
        else if (ch == 'S') burger[1]++;
        else if (ch == 'C') burger[2]++;
    }

    long long low = 0, high = 1e15, ans = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        long long required_b = max(0LL, mid * burger[0] - nb);
        long long required_s = max(0LL, mid * burger[1] - ns);
        long long required_c = max(0LL, mid * burger[2] - nc);
        
        long long cost = required_b * pb + required_s * ps + required_c * pc;
        
        if (cost <= r) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
