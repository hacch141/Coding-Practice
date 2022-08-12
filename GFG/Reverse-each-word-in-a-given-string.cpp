// Reverse each word in a given string

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
  
    string reverseWords (string s)
    {
        //code here.
        int start = 0;
        string str = "";
        
        for(int end = 0; end<s.length(); end++) {
            if(s[end] == '.') {
                int high = end-1;
                while(start<high) {
                    swap(s[start],s[high]);
                    start++;
                    high--;
                }
                start = end+1;
            }
        }
        
        int l = s.length()-1;
        while(start<l) {
            swap(s[start],s[l]);
            start++;
            l--;
        }
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
