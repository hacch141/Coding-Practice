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
};
