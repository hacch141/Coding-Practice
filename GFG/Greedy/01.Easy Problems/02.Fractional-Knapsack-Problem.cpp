// Fractional Knapsack Problem

class Solution {

    public double maximumValue(int[][] items, int n, int w) {

        // items[i][0] = weight
        // items[i][1] = value

        // Sort by value/weight ratio in descending order
        Arrays.sort(items, (a, b) -> 
            Long.compare(
                (long)b[1] * a[0],   // b.value * a.weight
                (long)a[1] * b[0]    // a.value * b.weight
            )
        );

        double ans = 0.0;

        for (int i = 0; i < n; i++) {

            int weight = items[i][0];
            int value  = items[i][1];

            if (weight <= w) {
                ans += value;
                w -= weight;
            } else {
                ans += (double)value * w / weight;
                break;
            }
        }

        return ans;
    }
}

// ======================================================================================

#include <bits/stdc++.h> 

static bool compare(pair<int,int>& p1, pair<int,int>& p2) {
    double r1 = (double)p1.second / (double)p1.first;
    double r2 = (double)p2.second / (double)p2.first;
    return r1 >= r2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),compare);
    double ans = 0;

    for(int i=0; i<n; i++) {
        int weight = items[i].first;
        int value = items[i].second;
        if(weight <= w) {
            ans += value;
            w -= weight;
        }
        else {
            ans += ((double)value / (double)weight) * w;
            break;
        }
    }

    return ans;
}
// T : O(N * Log N + N)
// S : O(1)
