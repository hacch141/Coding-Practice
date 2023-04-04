class Solution{
  public:
  
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        long long low = 0;
        long long high = n-1;
        
        while(low<=high) {
            
            long long mid = (high-low)/2 + low;
            
            if(x == v[mid]) {
                return (int)mid;
            }
            
            else if(x > v[mid]) {
                low = mid+1;
            }
            
            else {
                high = mid-1;
            }
            
        }
        return high;
    }
};
