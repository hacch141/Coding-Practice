// Book Allocation Problem

#include <bits/stdc++.h>

int bs(vector<int> &arr, int &books) {
    int students = 1;
    int currBooks = 0;
    for(auto i : arr) {
        if(currBooks + i <= books) {
            currBooks += i;
        }
        else {
            students++;
            currBooks = i;
        }
    }

    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.

    if(m > n) return -1;

    int low = 0;
    int high = 0;

    for(auto i : arr) {
        low = max(low,i);
        high += i;
    }

    while(low <= high) {
        int mid = (high-low)/2 + low;
        int students = bs(arr,mid);
        if(students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return low;
}
// T : O(N + N*log(sum(arr[])-max(arr[])+1))
// S : O(1)
