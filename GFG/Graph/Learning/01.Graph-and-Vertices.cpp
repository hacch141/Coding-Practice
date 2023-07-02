// Graph and Vertices

class Solution {
  public:
    long long count(int n) {
        // your code here
        
        // # of undirected edges = nC2
        // # of directed edges = nC2 * 2
        
        // all edge has 2 possibility take or not take 
        
        return 1LL * (pow(2,n*(n-1)/2));
    }
};

// T : O(1)
// S : O(1)
