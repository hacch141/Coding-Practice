// Painter's partition

#include <bits/stdc++.h>

int bs(vector<int> &arr, int &area) {
    int cnt = 1;
    int a = 0;
    for(auto i : arr) {
        if(a + i <= area) {
            a += i;
        }
        else {
            cnt++;
            a = i;
        }
    }
    return cnt;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int low = 0;
    int high = 0;

    for(auto i : boards) {
        low = max(low,i);
        high += i;
    }

    while(low <= high) {
        int mid = (high-low)/2 + low;
        int painters = bs(boards,mid);
        if(painters > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return low;
}
// T : O(N + N*Log(high-loq))
// S : O(1)
