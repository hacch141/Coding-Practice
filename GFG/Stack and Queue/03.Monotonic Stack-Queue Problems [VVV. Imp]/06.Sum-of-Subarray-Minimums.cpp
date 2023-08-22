// Sum of Subarray Minimums


// Fraz
#include <bits/stdc++.h>

int sumSubarrayMins(vector<int>&arr) {
    // Write your code here.
    stack<int> preST, nextST;
    int n = arr.size();
    vector<int> preSmaller(n), nextSmaller(n);

    // for ignoring this two commented while loops
    // to add values for remaining elements ele in stack
    for(int i=0; i<n; i++) {
        nextSmaller[i] = n-i-1;
        preSmaller[i] = i;
    }

    for (int i=0; i<n; i++) {
        while(!nextST.empty() && arr[i] < arr[nextST.top()]) {
            nextSmaller[nextST.top()] = i-nextST.top()-1;
            nextST.pop();
        }
        nextST.push(i);
    }
    // while(!nextST.empty()) {
    //     nextSmaller[nextST.top()] = n-nextST.top()-1;
    //     nextST.pop();
    // }


    for(int i=n-1; i>=0; i--) {
        while(!preST.empty() && arr[i] <= arr[preST.top()]) {
            preSmaller[preST.top()] = preST.top()-i-1;
            preST.pop();
        }
        preST.push(i);
    }
    // while(!preST.empty()) {
    //     preSmaller[preST.top()] = preST.top();
    //     preST.pop();
    // }

    long long ans = 0;
    int mod = 1e9+7;
    for(int i=0; i<n; i++) {
        ans += (arr[i] * (preSmaller[i] + 1) * (nextSmaller[i] + 1))%mod;
    }

    return ans;
}
// T : O(N)
// S : O(N)


// Anurag Codes
#include <bits/stdc++.h>

int sumSubarrayMins(vector<int>&arr) {
    // Write your code here.
    stack<pair<int,int>> leftst, rightst;
    int n = arr.size();
    vector<int> leftSmaller(n), rightSmaller(n);

    for (int i=0; i<n; i++) {
        int count = 1;
        while (!leftst.empty() && leftst.top().first > arr[i]) {
            count += leftst.top().second;
            leftst.pop();
        }
        leftst.push({arr[i],count});
        leftSmaller[i] = count;
    }


    for(int i=n-1; i>=0; i--) {
        int count = 1;
        while(!rightst.empty() && rightst.top().first >= arr[i]) {
            count += rightst.top().second;
            rightst.pop();
        }
        rightst.push({arr[i],count});
        rightSmaller[i] = count;
    }

    long long ans = 0;
    int mod = 1e9+7;
    for(int i=0; i<n; i++) {
        ans += (arr[i] * leftSmaller[i] * rightSmaller[i])%mod;
    }

    return ans;
}
// T : O(N)
// S : O(N)
