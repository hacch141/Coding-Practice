class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        unordered_map<int,int> mp;
        mp[0] = 1;
        
        int prefix = 0;
        int ans = 0;
        
        for(int i=0; i<N; i++) {
            prefix += Arr[i];
            if(mp.find(prefix-k) != mp.end()) {
                ans += mp[prefix-k];
            }
            mp[prefix]++;
        }
        
        return ans;
    }
};
