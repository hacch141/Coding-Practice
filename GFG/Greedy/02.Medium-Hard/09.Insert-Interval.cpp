// Insert Interval

#include <bits/stdc++.h>

vector<vector<int>> addInterval(vector<vector<int>> &intervals, int n, vector<int> &newInterval)
{
    // Write your code here
    vector<vector<int>> ans;

    int i = 0;
    // Add intervals that come before the new interval
    while (i < n && intervals[i][1] < newInterval[0]) {
        ans.push_back(intervals[i]);
        i++;
    }

    // Merge overlapping intervals
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push_back(newInterval);

    // Add intervals that come after the new interval
    while (i < n) {
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}

// T : O(N)
// S : O(N)
