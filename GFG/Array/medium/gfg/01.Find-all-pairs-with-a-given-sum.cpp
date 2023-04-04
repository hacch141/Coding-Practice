class Solution{
    public:
    
    // using hashmap
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Your code goes here   
        vector<pair<int,int>> ans;
        unordered_map<int,int> mp;
        
        for(int i=0; i<N; i++)  {
            mp[A[i]]++;
        }
        
        for(int i=0; i<M; i++) {
            if(mp.find(X-B[i]) != mp.end()) {
                ans.push_back({X-B[i],B[i]});
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
    
// ==========================================================================================
    
    // using binary search
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Your code goes here   
        vector<pair<int,int>> ans;
        sort(A,A+N);
        sort(B,B+M);
        
        for(int i=0; i<N; i++)  {
            
            int target = X-A[i];
            int low = 0;
            int high = M-1;
            
            while(low<=high) {
                
                int mid = (high-low)/2 + low;
                
                if(B[mid] == target) {
                    ans.push_back({A[i],target});
                    break;
                }
                else if(B[mid] < target) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
                
            }
        }
        return ans;
    }
};
