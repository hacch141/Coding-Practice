// Division without using multiplication, division and mod operator

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        //code here
        long long sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        long long quotient = 0;
        while (dividend >= divisor) {
            dividend -= divisor;
            quotient++;
        }
        
        return sign*quotient;
    }
};



class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        //code here
        long long sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        long long quotient = 0, temp = 0;
        for(int i=31; i>=0; i--) {
            if(temp + (divisor<<i) <= dividend) {
                temp += (divisor<<i);
                quotient += 1LL<<i;
            }
        }
        
        return sign*quotient;
    }
};

// T : O(Log N)
// S : O(1)
