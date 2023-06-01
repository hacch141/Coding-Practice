// Two numbers with odd occurrences

class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        long long int XOR = 0;
        for(long long int i=0; i<N; i++) {
            XOR ^= Arr[i];
        }
        int pos = 0;
        while(XOR) {
            if(XOR&1) {
                break;
            }
            pos++;
            XOR >>= 1;
        }
        
        long long int ans1 = 0;
        long long int ans2 = 0;
        for(long long int i=0; i<N; i++) {
            if(Arr[i] & (1<<pos)) {
                ans1 ^= Arr[i];
            }
            else {
                ans2 ^= Arr[i];
            }
        }
        
        vector<long long int> ans;
        if (ans1>ans2) {
            ans.push_back(ans1);
            ans.push_back(ans2);
        }
        else {
            ans.push_back(ans2);
            ans.push_back(ans1);
        }
        
        return ans;
    }
};

// T : O(N)
// S : O(1)
