// Find first repeated character

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends

const int CHAR = 256;
string firstRepChar(string s)
{
    //code here.
    string ans = "-1";
    int count[CHAR] = {0};
    for(int i=0; i<s.length(); i++) {
        if(count[s[i]]>0) {
            ans = s[i];
            return ans;
        }
        else {
            count[s[i]]++;
        }
    }
    return ans;
}
