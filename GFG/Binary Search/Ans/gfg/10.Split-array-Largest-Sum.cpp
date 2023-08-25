// Split array - Largest Sum

#include <bits/stdc++.h>

int bs(vector<int> &a, int &sum) {
    int s = 0;
    int cnt = 1;
    for(auto i : a) {
        if(s + i <= sum) {
            s += i;
        }
        else {
            cnt++;
            s = i;
        }
    }

    return cnt;
}

int largestSubarraySumMinimized(vector<int> a, int k) {
    // Write Your Code Here
    int low = INT_MIN;
    int high = 0;
    for(auto i : a) {
        low = max(low,i);
        high += i;
    }

    while(low <= high) {
        int mid = (high-low)/2 + low;
        int splits = bs(a,mid);
        if(splits > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return low;
}
// T : O(N + N*Log(high-low))
// S : O(1)
