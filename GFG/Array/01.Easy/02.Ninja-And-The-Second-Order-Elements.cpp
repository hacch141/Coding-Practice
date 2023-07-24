// Ninja And The Second Order Elements

vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
    int maxi1 = INT_MIN;
    int maxi = INT_MIN;
    int mini1 = INT_MAX;
    int mini = INT_MAX;

    for(int i=0; i<n; i++) {
        if(a[i] > maxi) {
            maxi1 = maxi;
            maxi = a[i];
        }
        else if(a[i] > maxi1) {
            maxi1 = a[i];
        }

        if(a[i] < mini) {
            mini1 = mini;
            mini = a[i];
        }
        else if(a[i] <mini1) {
            mini1 = a[i];
        }
    }
    return {maxi1,mini1};
}

// T : O(N)
// S : O(1)
