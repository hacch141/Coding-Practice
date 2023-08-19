// Count subarrays with given sum

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    // Write Your Code Here
    unordered_map<int,int> mp;
    mp[0] = 1;
    
    int ans = 0;
    int sum = 0;

    for(auto i : arr) {
        sum += i;
        int rem = sum - k;
        if(mp.find(rem) != mp.end()) {
            ans += mp[rem];
        }
        mp[sum]++;
    }

    return ans;
}

// T : O(N)
// S : O(N)



/*
    Time Complexity: O(N^2)
    Space Complexity: O(1)

    Where 'N' is the number of elements in the array/list 'arr'.
*/

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {

    int n = arr.size();
    int res = 0;

    // Calculate all subarrays.
    for (int i = 0; i < n; i++) {
        int currSum = 0;

        for (int j = i; j < n; j++) {

            // Calculate required sum.
            currSum += arr[j];

            // Check if currSum is equal to required sum.
            if (currSum == k) {
                res += 1;
            }
            else if(currSum > k) break;
        }
    }

    return res;
}
