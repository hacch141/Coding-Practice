// Sieve of Eratosthenes

vector<int> countPrimes(int n)
{
    // Write your code here.
    vector<int> ans;
    vector<bool> primes(n+1,true);
    for(int i=2; i*i<=n; i++) {
        if(primes[i] == true) {
            for(int j=i*i; j<=n; j+=i) {
                primes[j] = false;
            }
        }
    }

    for(int i=2; i<=n; i++) {
        if(primes[i] && n%i==0)
            ans.push_back(i);
    }

    return ans;
}
// T : O(Nlog(log(N)))
// S : O(N)
