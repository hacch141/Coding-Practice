// Merge Intervals

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
