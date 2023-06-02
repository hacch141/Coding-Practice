// Implement Atoi

class Solution{
  public:
    /*You are required to complete this method */
    
    int convert(string num, bool sign) {
        int ans = 0;
        int n = num.length();
        for(int i=0; i<n; i++) {
            if(sign && (long long)ans*10 + (num[i]-'0') >= (long long)INT_MAX+1) {
                return INT_MIN;
            }
            if(!sign && (long long)ans*10 + (num[i]-'0') >= (long long)INT_MAX) {
                return INT_MAX;
            }
            ans = ans*10 + (num[i]-'0');
        }
        return sign ? -ans : ans;
    }
    
    int atoi(string str) {
        //Your code here
        if(str[0]=='+') return -1;
        
        string num = "";
        int n = str.length();
        bool sign = false;
        
        int i = 0;
        if(str[i]=='-') {
            sign = true;
            i++;
        }
        
        while(i<n && (str[i]>='0' && str[i]<='9')) {
            num += str[i];
            i++;
        }
        if(i!=n) return -1;
                
        return convert(num,sign);
    }
};


// T : O(n)
// S : O(1)
