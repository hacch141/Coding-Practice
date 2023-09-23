// Best Time to Buy and Sell Stock

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mini = INT_MAX;
    int ans = 0;
    for(auto i : prices) {
        ans = max(ans,i-mini);
        mini = min(mini,i);
    }
    return ans;
}

// T : O(N)
// S : O(1)
