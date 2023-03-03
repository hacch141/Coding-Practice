// 28. Find the Index of the First Occurrence in a String

class Solution {

private:
    bool isValid(int start, int m, string haystack, string needle) {
        for(int i=start; i<start+m; i++) {
            if(haystack[i] != needle[i-start]) return false;
        }
        return true;
    }

public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int i=0; i<=n-m; i++) {
            if(isValid(i,m,haystack,needle)) return i;
        }
        return -1;
    }
    
    // =======================================================
    
    
    int strStr(string haystack, string needle) {
      return haystack.find(needle);
    }

    // =======================================================
    
    string st(string & haystack, int i, int j ){
        string temp = "";
        for (int k = i; k<=j; k++){
            temp += haystack[k];
        }
        return temp;

    }
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        if ((n>m) || (n==m && haystack != needle ))
        return -1;

        for (int i = n-1; i<m; i++){
            if (st(haystack, i-n+1, i) == needle){
                return i-n+1;
            }
        }
        
        return -1;
    }

    // =======================================================
    int strStr(string h, string n) {
        if(n.length()>h.length()) return -1;
        for(int i = 0; i<h.length()-n.length()+1; i++){
            if(h.substr(i, n.length())==n) return i;
        }
        return -1;
    }
    
    // =======================================================
    
    
};
