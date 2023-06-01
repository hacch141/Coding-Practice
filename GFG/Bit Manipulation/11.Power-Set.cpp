// Power Set

class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n = s.length();
		    int cnt = (1<<n);
		    vector<string> ans;
		    
		    for(int i=1; i<cnt; i++) {
		        string str = "";
		        for(int j=0; j<n; j++) {
		            if(i & (1<<j)) str += s[j];
		        }
		        ans.push_back(str);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

// T : O(n*2^n)
// S : O(n*2^n)
