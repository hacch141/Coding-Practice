// First Occurence of a Pattern in a Text

bool isValid(string &text, string &pat, int i, int j) {
	int m = pat.length();
	int n = text.length();

	while(i < n && j < m) {
		if(text[i] != pat[j]) {
			return false;
		}
		i++;
		j++;
	}

	return j==m;
}

int firstOccurence(string &text, string &pat){
	// Write your code here.
	const long long p = 26 , mod = 1e9+9;
	int n = text.length(), m = pat.length();

	long long p_pow = 1;
	for(int i=1; i<=m-1; i++) {
		p_pow = (p*p_pow)%mod;
	}

	if(m > n) return -1;

	long long hash_pat = 0;
	long long curr_text = 0;
	for(int i=0; i<m; i++) {
		hash_pat = ((hash_pat*p)%mod + (pat[i]-'a'+1))%mod;
		curr_text = ((curr_text*p)%mod + (text[i]-'a'+1))%mod;
	}

	if(hash_pat == curr_text) {
		if(isValid(text, pat, 0, 0)) return 0;
	}

	for(int i=0; i<n-m; i++) {

		// remove first element from window
		curr_text = (curr_text - ((text[i]-'a'+1)*p_pow)%mod + mod) % mod;
		// add next element in window
		curr_text = ((curr_text*p)%mod + (text[i+m]-'a' + 1))%mod;

		if(hash_pat == curr_text) {
			if(isValid(text, pat, i+1, 0)) return i+1;
		}
	}

	return -1;
}
// T : O(N+M)
// S : O(1)

// The average case and best case complexity of Rabin-Karp algorithm is O(m + n) and the worst case complexity is O(mn).
// The worst-case complexity occurs when spurious hits occur a number for all the windows.
