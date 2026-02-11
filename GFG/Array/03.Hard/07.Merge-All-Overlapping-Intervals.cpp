// Merge All Overlapping Intervals

class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals.length <= 1) return intervals;

        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        List<int[]> result = new ArrayList<>();

        int[] current = intervals[0];

        for (int i = 1; i < intervals.length; i++) {

            if (intervals[i][0] <= current[1]) {
                current[1] = Math.max(current[1], intervals[i][1]);
            } else {
                result.add(current);
                current = intervals[i];
            }
        }

        result.add(current);

        return result.toArray(new int[result.size()][]);
    }
}

// ===========================================================

#include <bits/stdc++.h>

static bool compare(vector<int>& v1, vector<int>& v2) {
  	if(v1[0] != v2[0]) {
  		  return v1[0] < v2[0];
  	}
  	return v1[1] < v2[1];
}

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
  	// Write your code here.
  	vector<vector<int>> ans;
  	sort(arr.begin(),arr.end(),compare);
  
  	int n = arr.size();
  	for(int i=0; i<n; i++) {
    		int start = arr[i][0];
    		int end = arr[i][1];
    		while(i+1<n && end >= arr[i+1][0]) {
      			end = max(end,arr[i+1][1]);
      			i++;
    		}
    		ans.push_back({start,end});
  	}
  	return ans;
}

// T : O(N*Log N + N)
// S : O(1)
