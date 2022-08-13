// Length of the longest substring

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        vector<int> prev(256,-1);
        int n = S.length();
        int i = 0;
        int ans = 0;
        
        for(int j=0; j<S.length(); j++) {
            i = max(i,prev[S[j]]+1);
            int maxend = j-i+1;
            ans = max(ans,maxend);
            prev[S[j]] = j;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends
