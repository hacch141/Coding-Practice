// Stickler Thief

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n) {
        // Your code here
        if(n==1) return arr[0];
        int prev2 = arr[0];
        int prev = max(arr[0],arr[1]);
        for(int i=2; i<n; i++) {
            int take = arr[i] + prev2;
            int nottake = prev;
            int curr = max(take,nottake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

// Same as previous one

// https://takeuforward.org/data-structure/dynamic-programming-house-robber-dp-6/
