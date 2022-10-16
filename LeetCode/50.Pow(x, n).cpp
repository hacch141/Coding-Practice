// 50. Pow(x, n)

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long int p = n;
        if(n<0) {
            p *= -1;
        }
        
        while(p){
            if(p%2){
                ans *= x;
                p--;
            }
            else{
                x *= x;
                p /= 2;
            }
        }
        if(n<0) {
            ans = (double) (1.0)/(double) (ans);
        } 
        return ans;
    }
};
