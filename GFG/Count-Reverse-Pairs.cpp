class Solution {
    
  private:
  
    int merge(vector<int>& arr, int start, int mid, int end) {
        int j = mid+1;
        int cnt = 0;
        for(int i=start; i<=mid; i++) {
            while(arr[i] > 2*arr[j] && j<=end) {
                j++;
            }
            cnt += j - (mid+1);
        }
        
        vector<int> v;
        int left = start;
        int right = mid+1;
        while(left<=mid && right<=end) {
            if(arr[left] <= arr[right]) {
                v.push_back(arr[left++]);
            }
            else {
                v.push_back(arr[right++]);
            }
        }
        while(left <= mid) v.push_back(arr[left++]);
        while(right <= end) v.push_back(arr[right++]);
        
        for(int i=start; i<=end; i++) {
            arr[i] = v[i-start];
        }
        return cnt;
    }
  
    int mergeSort(vector<int>& arr, int start, int end) {
        if(start >= end) return 0;
        int inv = 0;
        int mid = (start+end)/2;
        inv += mergeSort(arr, start, mid);
        inv += mergeSort(arr, mid+1, end);
        inv += merge(arr, start, mid, end);
        return inv;
    }
    
  public:
    int countRevPairs(int n, vector<int> arr) {
        // Code here
        return mergeSort(arr, 0, n-1);
    }
};
