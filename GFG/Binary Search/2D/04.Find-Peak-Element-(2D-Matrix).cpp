// Find Peak Element (2D Matrix)

#include <bits/stdc++.h>

int getMaxR(vector<int> &arr) {
    int maxi = INT_MIN;
    int ind = -1;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] > maxi) {
            maxi = arr[i];
            ind = i;
        }
    }
    return ind;
}

bool isValid(vector<vector<int>> &g, int &mid, int &colInd) {
    int n = g.size();

    if(mid == 0 && mid+1<n && g[mid][colInd] > g[mid+1][colInd]) {
        return true;
    }
    else if(mid == n-1 && mid-1>=0 && g[mid][colInd] > g[mid-1][colInd]) {
        return true;
    }
    else if(mid-1>=0 && mid+1<n && g[mid][colInd] > g[mid+1][colInd] && g[mid][colInd] > g[mid-1][colInd]) {
        return true;
    }
    return false;
}

vector<int> findPeakGrid(vector<vector<int>> &g){
    // Write your code here.  
    int n = g.size();
    int m = g[0].size();

    if(n==1 && m==1) return {0,0};
    if(n==1) return {0,getMaxR(g[0])};

    int low = 0;
    int high = n;

    while(low <= high) {
        int mid = (high-low)/2 + low;
        int colInd = getMaxR(g[mid]);

        if(isValid(g, mid, colInd)) return {mid,colInd};
        
        else if(mid-1 >= 0 && g[mid][colInd] < g[mid-1][colInd]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return {-1,-1};
}
// T : O(m*log(n))
// S : O(1)
