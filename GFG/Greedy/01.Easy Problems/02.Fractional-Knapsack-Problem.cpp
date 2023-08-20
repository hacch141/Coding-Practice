// Fractional Knapsack Problem

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
