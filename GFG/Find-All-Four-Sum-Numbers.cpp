class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int> > ans;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int sum1 = arr[i] + arr[j];
                int low = j+1;
                int high = n-1;
                while(low < high) {
                    int sum2 = arr[low] + arr[high];
                    if(sum1+sum2 < k) {
                        low++;
                    }
                    else if(sum1+sum2 > k) {
                        high--;
                    }
                    else {
                        vector<int> v(4,0);
                        v[0] = arr[i];
                        v[1] = arr[j];
                        v[2] = arr[low];
                        v[3] = arr[high];
                        ans.push_back(v);
                        while(low<high && arr[low]==v[2]) low++;
                        while(low<high && arr[high]==v[3]) high--;
                    }
                }
                while(j+1<n && arr[j]==arr[j+1]) j++;
            }
            while(i+1<n && arr[i]==arr[i+1]) i++;
        }
        return ans;
    }
};
