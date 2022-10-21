// 557. Reverse Words in a String III

class Solution {
public:
    
    void rev(string &s, int low, int high) {
        while(low <= high) {
            swap(s[low],s[high]);
            low++;
            high--;
        }
    }
    
    string reverseWords(string s) {
        int n = s.length();
        int start = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == ' ') {
                rev(s,start,i-1);
                start = i+1;
            }
        }
        rev(s,start,n-1);
        return s;
    }
};
