// Connect n ropes with minimum cost

class Solution {

    public int minCost(int[] ropes) {

        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        // Add all ropes to heap
        for (int rope : ropes) {
            minHeap.offer(rope);
        }

        int totalCost = 0;

        while (minHeap.size() > 1) {

            // Take two smallest ropes
            int first = minHeap.poll();
            int second = minHeap.poll();

            int cost = first + second;
            totalCost += cost;

            // Add combined rope back
            minHeap.offer(cost);
        }

        return totalCost;
    }
}

// =====================================================================

int minCost(int arr[], int n)
{
	int ans = 0;
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=0; i<n; i++) {
		pq.push(arr[i]);
	}
	while(pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		ans += (a+b);
		pq.push(a+b);
	}
	return ans;
}
// T : O(N*LogN)
// S : O(N)
