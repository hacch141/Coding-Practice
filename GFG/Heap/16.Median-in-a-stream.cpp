// Median in a stream

class MedianFinder {
    PriorityQueue<Double> pq1, pq2;

    public MedianFinder() {
        pq1 = new PriorityQueue<>((a, b) -> Double.compare(b, a));
        pq2 = new PriorityQueue<>();
    }
    
    public void addNum(int num) {
        pq1.add((double)num);
        pq2.add(pq1.poll());

        if (pq1.size() < pq2.size()) {
            pq1.add(pq2.poll());
        }
    }
    
    public double findMedian() {

        if (pq1.size() == pq2.size()) {
            return (pq1.peek() + pq2.peek()) /  2;
        }

        return pq1.peek();
    }
}

// =========================================================================

#include <bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n) {
    // Write your code here
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    vector<int> ans;
    for (auto i : arr) {
        pq1.push(i);
        pq2.push(pq1.top());
        pq1.pop();
        if (pq1.size() < pq2.size()) {
            pq1.push(pq2.top());
            pq2.pop();
        }

        if (pq1.size() > pq2.size()) {
            ans.push_back(pq1.top());
        } else {
            ans.push_back((pq1.top() + pq2.top()) / 2);
        }
    }
    return ans;
}

// T : O(N*LogN)
// S : O(N)
