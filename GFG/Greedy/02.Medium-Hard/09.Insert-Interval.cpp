// Insert Interval

class Solution {

    public int[][] insert(int[][] intervals, int[] newInterval) {

        int n = intervals.length;

        // Create new array with one extra space
        int[][] all = new int[n + 1][2];

        for (int i = 0; i < n; i++) {
            all[i] = intervals[i];
        }

        all[n] = newInterval;

        // Sort by start time
        Arrays.sort(all, (a, b) -> a[0] - b[0]);

        List<int[]> ans = new ArrayList<>();

        // Take first interval as current
        int[] curr = all[0];

        for (int i = 1; i < all.length; i++) {

            // If overlapping → merge
            if (curr[1] >= all[i][0]) {
                curr[1] = Math.max(curr[1], all[i][1]);
            } 
            else {
                // No overlap → push current
                ans.add(curr);
                curr = all[i];
            }
        }

        // Add last interval
        ans.add(curr);

        return ans.toArray(new int[ans.size()][]);
    }
}

// ======================================================================

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
