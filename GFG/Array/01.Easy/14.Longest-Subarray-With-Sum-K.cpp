// Longest Subarray With Sum K.

#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    int  n = nums.size();
    unordered_map<int,int> mp;
    int sum = 0;
    int ans = 0;

    for(int i=0; i<n; i++) {
        sum += nums[i];
        if(sum == k) ans = i+1;
        int rem = sum - k;
        if(mp.find(rem) != mp.end()) {
            ans = max(ans,i-mp[rem]);
        }

        if(mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }
    return ans;
}

// T : O(N)
// S : O(N)
