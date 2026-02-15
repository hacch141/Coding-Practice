// Kth largest element in an array

class Solution {

    public int[] kLargest(int[] arr, int n, int k) {

        // Min heap (Default)
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int i = 0; i < n; i++) {

            pq.add(arr[i]);

            // Maintain heap size <= k
            if (pq.size() > k) {
                pq.poll();
            }
        }

        int[] result = new int[k];
        int index = 0;

        while (!pq.isEmpty()) {
            result[index++] = pq.poll();
        }

        return result;
    }
}

// =======================================================================

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
