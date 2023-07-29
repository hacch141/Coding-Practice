// Connect n ropes with minimum cost

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
