// Kth smallest element in an array

class Solution {

    public int[] kSmallest(int[] arr, int n, int k) {

        // Max Heap (reverse order)
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);

        for (int i = 0; i < n; i++) {

            pq.offer(arr[i]);

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

// ==================================================================

#include <bits/stdc++.h>

vector<int> kSmallset(int arr[], int n, int k) {
    // Write your code here
    priority_queue<int> pq;
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
