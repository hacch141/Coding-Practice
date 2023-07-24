// Maximum Points From Cards

int maxPoints(vector<int>&arr , int K){
    // Write your code here.
    int n = arr.size();

    int sum = 0;
    for(auto i : arr) {
        sum += i;
    }

    if(K == n) return sum;

    int win = n-K;
    int i=0, j=0;
    int ans = 0;

    while(j<n) {
        sum -= arr[j];
        while(i<j && j-i+1 > win) {
            sum += arr[i];
            i++;
        }

        if(j-i+1 == win) {
            ans = max(ans,sum);
        }
        j++;
    }
    return ans;
}

// T : O(N)
// S : O(1)
