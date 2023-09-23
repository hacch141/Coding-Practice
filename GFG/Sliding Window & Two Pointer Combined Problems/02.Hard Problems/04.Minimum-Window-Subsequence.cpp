// Minimum Window Subsequence

string minWindow(string S, string T)
{
	// Write your Code here
	int n = S.length();
	int m = T.length();

	string ans = "";
	for(int i=0; i<n; i++) {
		string curr = "";
		int ptr = 0;
		if(S[i] == T[ptr]) {
			for(int j=i; j<n; j++) {
				if(S[j]==T[ptr]) ptr++;
				if(ptr==m) {
					int st = i;
					int end = j;
					if(ans.length()==0 || end-st+1<ans.length()) {
						ans = S.substr(st,end-st+1);
					}
					break;
				} 
			}
		}
	}

	return ans;
}
// T : O(N^2)
// S : O(N)
