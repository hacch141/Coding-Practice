// Sort Characters by frequency

string sortByFrequency(int n, string& s) {
  	// Write Your Code here
  	unordered_map<char,int> mp;
  	for(auto i : s) {
  	  	mp[i]++;
  	}
  
  	priority_queue<pair<int,char>> pq;
  	for(auto i : mp) {
  	  	pq.push({i.second,i.first});
  	}
  
  	string ans;
  	while(!pq.empty()) {
    		auto i = pq.top();
    		int freq = i.first;
    		char c = i.second;
    		pq.pop();
    		while(freq--) {
    		  	ans += c;
    		}
  	}
  	return ans;
}
// T : O(N * Log N + N)
// S : O(N)



string sortByFrequency(int n, string& s) {
  	// Write Your Code here
  	priority_queue<pair<int,char>> pq;
  	sort(s.begin(),s.end());
  
  	char prev = s[0];
  	int freq = 1;
  
  	for(int i=1; i<n; i++) {
    		char c = s[i];
    		if(c == prev) {
    			  freq++;
    		}
    		else {
      			pq.push({freq,prev});
      			freq = 1;
      			prev = c;
    		}
  	}
  	pq.push({freq,prev});
  
  	string ans;
  	while(!pq.empty()) {
    		auto i = pq.top();
    		int freq = i.first;
    		char c = i.second;
    		pq.pop();
    		while(freq--) {
    			  ans += c;
    		}
  	}
  
  	return ans;
}
// T : (N * Log N + N)
// S : O(N)
