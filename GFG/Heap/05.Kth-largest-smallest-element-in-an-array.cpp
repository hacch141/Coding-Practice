// Kth largest/smallest element in an array

#include <bits/stdc++.h>

vector<int> kLargest(int arr[], int n, int k) {
    // Write your code here
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++) {
        pq.push(arr[i]);
        while(pq.size() > k) {
            pq.pop();
        }
    }
    vector<int> ans;
    while(!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}

// T : O(N * Logk)
// S : O(K)
