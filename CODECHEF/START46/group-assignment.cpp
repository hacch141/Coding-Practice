// Group Assignment
// Problem Code:GRPASSN

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long n;
        int a;
        cin >> n;
        map<int, int> mp;
        
        for(int i=0; i<n; i++ ) {
            cin>>a;
            mp[a]++;
        }

        bool ans = true;
        for(auto i : mp) {
            if((i.second%i.first)!=0) {
                ans = false;
            }
        }
        
        if(ans) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}