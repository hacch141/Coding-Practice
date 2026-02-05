// Sort Characters by frequency

class Solution {
    public String frequencySort(String s) {
        Map<Character,Integer> mp = new HashMap<>();
        for (char ch : s.toCharArray()) {
            mp.put(ch, mp.getOrDefault(ch, 0) + 1);
        }

        List<Map.Entry<Character,Integer>> f = new ArrayList<>(mp.entrySet());
        Collections.sort(f, (a, b) -> Integer.compare(b.getValue(), a.getValue()));

        StringBuilder sb = new StringBuilder();
        for (Map.Entry<Character,Integer> e : f) {
            for (int i = 0; i < e.getValue(); i++) {
                sb.append(e.getKey());
            }
        }

        return sb.toString();
    }
}

// =====================================================================================

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
