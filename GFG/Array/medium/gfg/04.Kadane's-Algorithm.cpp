class Solution{
    public:
  
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        int sum = 0;
        int maxSum = 0;
        int maxEle = INT_MIN;

        for(int i=0; i<n; i++) {

            sum += arr[i];
            maxSum = max(maxSum,sum);
            maxEle = max(maxEle,arr[i]);

            if(sum<0) {
                sum = 0;
            }

        }

        if(maxSum==0) return maxEle;

        return maxSum;
      
    }
};
