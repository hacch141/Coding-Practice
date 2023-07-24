// Count Distinct Subarrays With At Most K Odd Elements

int distinctSubKOdds(vector<int> &arr, int k)
{
	// Write your code here
	int n = arr.size();

	vector<int> prefix(n+1,0);
	prefix[0] = 1;

	int cntodd = 0;
	int ans = 0;
	for(int i=0; i<n; i++) {
		cntodd += arr[i]%2;
		if(cntodd >= k) {
			ans += prefix[cntodd-k];
		}
		prefix[cntodd]++;
	}
	return ans;
}
// T : O(N)
// S : O(N)


int distinctSubKOdds(vector<int> &arr, int k)
{
	// Write your code here
    int n = arr.size();
    
    int f = 0;
    int cntOdd = 0;

    int i=0, j=0;
    int ans = 0;
    while(j<n) {
        cntOdd += arr[j]%2;

        if(cntOdd == k) f++;

        if(cntOdd > k) {
            while(i<j && cntOdd > k) {
                cntOdd -= arr[i]%2;
                i++;
                ans += f;
            }
            f = 1;
        }
        j++;
    }

    while(i<j && cntOdd == k) {
        cntOdd -= arr[i]%2;
        i++;
        ans += f;
    }
    
    return ans;
}
// T : O(N)
// S : O(1)
