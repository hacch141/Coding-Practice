/// Kth Largest Element In A Stream

class KthLargest {

    private PriorityQueue<Integer> minHeap;
    private int k;

    public KthLargest(int k, int[] nums) {

        this.k = k;
        minHeap = new PriorityQueue<>();

        for (int num : nums) {
            add(num);
        }
    }

    public int add(int val) {

        minHeap.offer(val);

        if (minHeap.size() > k) {
            minHeap.poll();
        }

        return minHeap.peek();
    }
}

// ==========================================================================

#include <algorithm>

class Kthlargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    Kthlargest(int k, vector<int> &arr) {
        for(auto i : arr) {
            pq.push(i);
            while(pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int num) {
        pq.push(num);
        pq.pop();
        return pq.top();
    }

};

// T : O(N*LogN)
// S : O(N)
