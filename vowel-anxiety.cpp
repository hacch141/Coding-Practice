// Vowel Anxiety
// Problem Code:VOWANX

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int vovelcnt = 0;
        deque<char> q;
        for(int i=0; i<n; i++) {
            if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
                vovelcnt++;
            }
            if(vovelcnt%2 == 0) {
                q.push_back(s[i]);
            }
            else {
                q.push_front(s[i]);
            }
        }
        if(vovelcnt%2 == 0) {
            while(!q.empty()) {
                cout << q.front();
                q.pop_front();
            }
        }
        else {
            while(!q.empty()) {
                cout << q.back();
                q.pop_back();
            }
        }
        cout <<endl;
    }
    return 0;
}   