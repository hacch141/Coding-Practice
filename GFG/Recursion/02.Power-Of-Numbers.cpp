// Power Of Numbers


// Recursion
class Solution{
    public:
    //You need to complete this fucntion
    int modulo = 1e9+7;
    
    long long power(int N,int R)
    {
        //Your code here
        if(N==1 || N==0) return N;
        if(R==0) return 1;
        
        long long half = power(N,R/2);
        long long ans = (half*half)%modulo;
        if(R%2==1) {
            ans = (ans*N)%modulo;
        }
        
        return ans;
    }
};


// Iterative
class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int N,int R)
    {
        //Your code here
        bool sign = false;
        if(R<0) {
            sign = true;
            R = -R;
        }
        long long ans;
        long long num = (double)N;
        long long modulo = 1e9+7;
        
        if(R&1) {
            ans = N;
        }
        else {
            ans = 1;
        }
        
        R >>= 1;
        while(R) {
            num = (num*num)%modulo;
            if(R&1) {
                ans = (ans*num)%modulo;
            }
            R >>= 1;
        }
        
        if(sign) return (long long)1.0/ans;
        return (long long)ans;
    }
};

// T : O(Log N)
// S : O(1)




class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int N,int R)
    {
        //Your code here
        bool sign = false;
        if(R<0) {
            sign = true;
            R = -R;
        }
        long long ans = 1;
        long long num = (double)N;
        long long modulo = 1e9+7;
        
        while(R) {
            if(R&1) {
                ans = (ans*num)%modulo;
            }
            num = (num*num)%modulo;
            R >>= 1;
        }
        
        if(sign) return (long long)1/ans;
        return (long long)ans;
    }
};
