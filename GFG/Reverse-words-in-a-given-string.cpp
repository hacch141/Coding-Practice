// Reverse words in a given string

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        vector<string> temp;
        string str = "";
        for(int i=0; i<S.length(); i++) {
            if(S[i]=='.') {
                temp.push_back(str);
                temp.push_back(".");
                str = "";
            }
            else {
                str += S[i];
            }
        }
        temp.push_back(str);
        reverse(temp.begin(),temp.end());
        S = "";
        for(auto st : temp) {
            S += st;
        }
        return S;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends
