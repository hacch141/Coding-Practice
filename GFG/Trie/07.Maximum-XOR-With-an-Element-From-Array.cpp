// Maximum XOR With an Element From Array

#include <bits/stdc++.h>

struct Node {
  	Node* bits[2];
  
  	Node() {
    		bits[0] = NULL;
    		bits[1] = NULL;
  	}
  
  	bool containsKey(int bit) {
  		  return (bits[bit] != NULL);
  	}
  
  	Node* get(int bit) {
  		  return bits[bit];
  	}
  
  	void put(int bit, Node* node) {
  		  bits[bit] = node;
  	}
};

class Trie {
  	private:
  	Node* root;
  
  	public:
  
  	Trie() {
  		  root = new Node();
  	}
  
  	void insert(int num) {
    		Node* node = root;
    		for(int i=31; i>=0; i--) {
      			int bit = (num>>i) & 1;
      			if(!node->containsKey(bit)) {
      				  node->put(bit, new Node());
      			}
      			node = node->get(bit);
    		}
  	}
  
  	int getMax(int num) {
    		Node* node = root;
    		int maxi = 0;
    
    		for(int i=31; i>=0; i--) {
      			int bit = (num>>i) & 1;
      			if(node->containsKey(1-bit)) {
        				maxi = maxi | (1<<i);
        				node = node->get(1-bit);
      			}
      			else {
      				  node = node->get(bit);
      			}
    		}
    
    		return maxi;
  	}
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
  	//	Write your coode here.
  	sort(arr.begin(),arr.end());
  	vector<pair<int,pair<int,int>>> v;
  
  	int n = queries.size();
  	for(int i=0; i<n; i++) {
  		  v.push_back({queries[i][1],{queries[i][0],i}});
  	}
  
  	sort(v.begin(),v.end());
  
  	Trie t;
  	vector<int> ans(n,0);
  	
  	int ind = 0;
  	int size = arr.size();
  	
  	for(int i=0; i<n; i++) {
    		int ai = v[i].first;
    		int xi = v[i].second.first;
    		int qInd = v[i].second.second;
    		while(ind<size && arr[ind]<=ai) {
      			t.insert(arr[ind]);
      			ind++;
    		}
    		if(ind==0) ans[qInd] = -1;
    		else ans[qInd] = t.getMax(xi);
  	}
  
  	return ans;
}

// T : O(M) + O(MlogM) + O(M*32 + N*32)
// S : O(32*N)
