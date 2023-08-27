// num pow

int power(int N, int R){
    // Write your code here.
    long long ans = 1;
    long long num = N;
    long long pow = R;
    int mod = 1e9+7;

    while(pow) {
        if(pow&1) {
            ans = (ans*num) % mod;
        }
        num = (num*num) % mod;
        pow >>= 1;
    }
    return ans;
}
// T : O(log(r))
// S : O(1)


int power(int N, int R){
    // Write your code here.
    if(R == 1) return N;
    if(N <= 1) return N;
    int mod = 1e9+7;
    long long half = power(N,R/2);
    long long ans = (half*half) % mod;
    if(R%2 == 1) ans = (ans*N) % mod;
    return ans;
}
// T : O(log(r))
// S : O(log(r))
