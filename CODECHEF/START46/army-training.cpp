// Army Training
// Problem Code:ARMTRN

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        int sum=0, totalSum=0;
        long long ans = INT_MIN;

        for(int i=0; i<n; i++) {
            cin >> arr[i];
            totalSum += arr[i];
        }

        sort(arr, arr+n, greater<int>());
        int attack, defence;
        for(int j=0; j<n; j++) {
            attack = sum;
            defence = 1000*(n-j)-(totalSum-sum);
            ans = max(ans, (long long)attack*defence);
            sum += arr[j];
        }

        cout<<ans<<endl;
    }
    return 0;
}