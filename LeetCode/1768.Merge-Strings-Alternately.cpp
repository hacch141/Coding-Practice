// 1768. Merge Strings Alternately

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int ptr1 = 0;
        int ptr2 = 0;
        string ans = "";
        
        while(ptr1<n && ptr2<m) {
            ans += word1[ptr1++];
            ans += word2[ptr2++];
        }
        while(ptr1<n) {
            ans += word1[ptr1++];
        }
        while(ptr2<m) {
            ans += word2[ptr2++];
        }

        return ans;
    }
};
