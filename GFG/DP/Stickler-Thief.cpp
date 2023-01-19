class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int prev = arr[0];
        int prev2 = 0;
        for(int i=1; i<n; i++) {
            int pick = arr[i] + prev2;
            int notpick = 0 + prev;
            int curr = max(pick,notpick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
