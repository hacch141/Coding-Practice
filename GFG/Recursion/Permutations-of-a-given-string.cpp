// Permutations of a given string

class Solution
{
	public:
	
	void solve(string curr, string s, vector<string>& ans) {
	    if(s.length()==0) {
	        ans.push_back(curr);
	        return;
	    }
	    
	    for(int i=0; i<s.length(); i++) {
	        string l = s.substr(0,i);
	        string r = s.substr(i+1);
	        solve(curr+s[i],l+r,ans);
	    }
	}
	
	vector<string>find_permutation(string S) {
	    // Code here there
	    vector<string> ans;
	    string curr = "";
	    sort(S.begin(),S.end());
	    solve(curr, S, ans);
	    set<string> st(ans.begin(),ans.end());
        ans.assign(st.begin(),st.end());
	    return ans;
	}
};

// T : O(n! * n)
// S : O(n)
