// Merge K Sorted Arrays

#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    int n = kArrays.size();
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
    for(int i=0; i<n; i++) {
        pq.push({kArrays[i][0],{i,0}});
    }

    vector<int> ans;
    while(!pq.empty()) {
        int ele = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        ans.push_back(ele);
        y++;
        if(y < kArrays[x].size()) {
            pq.push({kArrays[x][y],{x,y}});
        }
    }

    return ans;
}

// T : O(N*K*LogK)
// S : O(K)
