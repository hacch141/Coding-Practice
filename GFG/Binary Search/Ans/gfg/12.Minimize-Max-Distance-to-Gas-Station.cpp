// Minimize Max Distance to Gas Station

// Using Heap
#include <bits/stdc++.h>

long double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.
	int n = arr.size();
	vector<int> howMany(n-1,0);
	priority_queue<pair<long double,int>> pq;
	
	for(int i=1; i<n; i++) {
		pq.push({abs(arr[i]-arr[i-1]),i-1});
	}

	while(k--) {
		long double diff = pq.top().first;
		int ind = pq.top().second;
		pq.pop();
		
		howMany[ind]++;
		long double newDiff = (long double)(abs(arr[ind+1]-arr[ind])/(long double)(howMany[ind]+1));
		pq.push({newDiff,ind});
	}

	return pq.top().first;
}
// T : O(N*Log N + K*Log N)
// S : O(N)


// Using Binary Search
#include <bits/stdc++.h>

int bs(vector<int>& arr, long double &dist) {
	int cnt = 0;
	for(int i=0; i<arr.size()-1; i++) {
		long double diff = abs(arr[i+1]-arr[i]);
		int partitions = diff/dist;
		if(partitions*dist == diff) partitions--;
		cnt += partitions;
	}
	return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.
	int n = arr.size();
	long double low = 0;
	long double high = 0;
	for(int i=1; i<n; i++) {
		high = max(high,(long double)arr[i]-arr[i-1]);
	}

	long double diff = 1e-6;
	while(high-low > diff) {
		long double mid = (high-low)/2 + low;
		int placements = bs(arr,mid);
		if(placements > k) {
			low = mid;
		}
		else {
			high = mid;
		}
	}
	return high;
}
// T : O(n + n*log(Len))
// S : O(1)
