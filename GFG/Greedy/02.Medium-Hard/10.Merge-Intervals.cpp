// Merge Intervals

class Solution {

    public int[][] merge(int[][] intervals) {

        if (intervals.length == 0)
            return new int[0][0];

        // 1️⃣ Sort by start time
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);

        List<int[]> ans = new ArrayList<>();

        // 2️⃣ Take first interval as current
        int[] curr = intervals[0];

        for (int i = 1; i < intervals.length; i++) {

            // If overlapping
            if (curr[1] >= intervals[i][0]) {
                curr[1] = Math.max(curr[1], intervals[i][1]);
            } 
            else {
                // No overlap → push current
                ans.add(curr);
                curr = intervals[i];
            }
        }

        // Add last interval
        ans.add(curr);

        return ans.toArray(new int[ans.size()][]);
    }
}

// =======================================================================

#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;

    int n = intervals.size();
    for(int i=0; i<n; i++) {
        int st = intervals[i][0];
        int end = intervals[i][1];
        while(i+1 < n && end >= intervals[i+1][0]) {
            end = max(end , intervals[i+1][1]);
            i++;
        }
        ans.push_back({st,end});
    }

    return ans;
}
// T : O(N LogN)
// S : O(N)
