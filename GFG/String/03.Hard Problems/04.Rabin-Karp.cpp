// Rabin Karp

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

vector<int> stringMatch(string text, string pattern) {
	// Write your code here.
	int n = text.length();
	int m = pattern.length();

	const long long p = 26, mod = 1e9+7;

	long long p_pow = 1;
	for(int i=1; i<=m-1; i++) {
		p_pow = (p*p_pow)%mod;
	}

	if(m > n) return {};

	vector<int> ans;

	long long hash_pat = 0, hash_text = 0;
	for(int i=0; i<m; i++) {
		hash_pat = ((hash_pat*p)%mod + (pattern[i]-'a'+1))%mod;
		hash_text = ((hash_text*p)%mod + (text[i]-'a'+1))%mod;
	}

	if(hash_pat == hash_text) {
		if(isValid(text, pattern, 0, 0)) ans.push_back(1);
	}

	for(int i=0; i<n-m; i++) {
		// remove first element from window
		hash_text = (hash_text - ((text[i]-'a'+1)*p_pow)%mod + mod) % mod;
		// add next element in window
		hash_text = ((hash_text*p)%mod + (text[i+m]-'a' + 1))%mod;

		if(hash_pat == hash_text) {
			if(isValid(text, pattern, i+1, 0)) {
				ans.push_back(i+2);
			}
		}
	}

	return ans;
}
// T : O(M+N)
// S : O(M)
