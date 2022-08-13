// Rank The Permutations

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int factorial(int n) {
        if(n==0) {
            return 1;
        }
        int fact = 1;
        for(int i=1; i<=n; i++) {
            fact *= i;
        }
        return fact;
    }

    const int CHAR = 256;
    int rank(string S){
        // code here
        int ans = 1;
        int n = S.length();
        long long mul = factorial(n);
        int count[CHAR] = {0};
        
        for(int i=0; i<n; i++) {
            count[S[i]]++;
            if(count[S[i]]>1) {
                return 0;
            }
        }
        for(int i=1; i<CHAR; i++) {
            count[i] += count[i-1];
        }
        for(int i=0; i<n-1; i++) {
            mul = mul/(n-i);
            ans = ans+count[S[i]-1]*mul;
            for(int j=S[i]; j<CHAR; j++) {
                count[j]--;
            }
        }
        return ans%1000003;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.rank(S)<<endl;
    }
    return 0;
}
// } Driver Code Ends
