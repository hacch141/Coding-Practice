// Count the number of subarrays with given xor K

#include <bits/stdc++.h>

int subarraysWithXorK(vector < int > a, int b) {
    // Write your code here
    int n = a.size();
    unordered_map<int,int> mp;
    mp[0] = 1;

    int XOR = 0;
    int ans = 0;

    for(int i=0; i<n; i++) {
        XOR ^= a[i];
        if(mp.find(XOR^b) != mp.end()) {
            ans += mp[XOR^b];
        }
        mp[XOR]++;
    }

    return ans;
}
// T : O(N)
// S : O(N)



int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            xorr = xorr ^ a[j];

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}
// T : O(N^2)
// S : O(1)


int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            int xorr = 0;
            for (int K = i; K <= j; K++) {
                xorr = xorr ^ a[K];
            }

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}
// T : O(N^3)
// S : O(1)
