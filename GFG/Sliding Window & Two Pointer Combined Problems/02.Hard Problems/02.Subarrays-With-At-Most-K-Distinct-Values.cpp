// Subarrays With At Most ‘K’ Distinct Values

#include <bits/stdc++.h> 
int kDistinctSubarrays(vector<int> &arr, int n, int k)
{
    // Write your code here
    unordered_map<int,int> mp;

    int i=0, j=0;
    int ans = 0;

    while(j<n) {
        mp[arr[j]]++;
        while(i<j && mp.size() > k) {
            mp[arr[i]]--;
            if(mp[arr[i]] == 0) mp.erase(mp.find(arr[i]));
            i++;
        }
        ans += (j-i+1);
        j++;
    }
    return ans;
}
// T : O(N)
// S : O(N)


int kDistinctSubarrays(vector<int> &arr, int n, int k)
{
    int count = 0;
    int l = 0, r = 0;
    unordered_map<int, int> hashMap;

    int size = 0;
    while (r < n)
    {
        hashMap[arr[r]]++;
        if (hashMap[arr[r]] == 1)
        {
            size++;
        }
        while (size > k)
        {
            hashMap[arr[l]]--;
            if (hashMap[arr[l]] == 0)
            {
                size--;
            }
            l++;
        }

        count += r - l + 1;
        r++;
    }
    
    return count;
}
// T : O(N)
// S : O(N)
