// Check whether K-th bit is set or not

class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        // Your code here
        // It can be a one liner logic!! Think of it!!
        int ans = (n>>k) & 1;
        return ans == 1 ? true : false;
    }
};

// T : O(1)
// S : O(1)
