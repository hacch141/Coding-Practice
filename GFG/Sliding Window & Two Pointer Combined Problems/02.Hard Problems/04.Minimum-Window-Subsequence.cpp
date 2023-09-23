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




string minWindow(string S, string T)
{
    // Write your Code here
    int n = S.length();
    int m = T.length();

    string ans = "";

    int i=0, j=0, mini=n;

    while(i<n) {
	if(S[i] == T[j]) {
	    j++;
	    if(j==m) {
		int end = i;
		j--;

		while(j>=0) {
		    if(S[i] == T[j]) {
			j--;
		    }
		    i--;
		}

		i++;
	        j++;
	
		if(end-i < mini) {
		    mini = end - i;
		    ans = S.substr(i,end-i+1);
		}
	    }
        }
        i++;
    }
    return ans;
}
