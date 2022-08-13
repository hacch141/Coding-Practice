// Count Occurences of Anagrams

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:

    bool aresame(int CT[], int CP[]) {
        for(int i=0; i<256; i++) {
            if(CT[i] != CP[i]) {
                return false;
            }
        }
        return true;
    }

    const int CHAR = 256;
	int search(string pat, string txt) {
	    // code here
	    if(pat.length() > txt.length()) {
	        return 0;
	    }
	    
	    int CT[CHAR] = {0};
	    int CP[CHAR] = {0};
	    for(int i=0; i<pat.length(); i++) {
	        CT[txt[i]]++;
	        CP[pat[i]]++;
	    }
	    
	    int ans = 0;
	    for(int i=pat.length(); i<txt.length(); i++) {
	        if(aresame(CT,CP)) {
	            ans++;
	        }
	        CT[txt[i]]++;
	        CT[txt[i-pat.length()]]--;
	    }
	    if(aresame(CT,CP)) {
	        ans++;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
