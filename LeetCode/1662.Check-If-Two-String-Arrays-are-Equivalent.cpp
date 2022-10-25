// 1662. Check If Two String Arrays are Equivalent

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0;
        int k = 0, l = 0;
        int m = word1.size();
        int n = word2.size();
        char c1, c2;
        while(i<m && j<n) {
            if(word1[i][k++] != word2[j][l++]) {
                return false;
            }
            if(k == word1[i].length()) {
                i++;
                k = 0;
            }
            if(l == word2[j].length()) {
                j++;
                l = 0;
            }
        }
        
        return i == m && j == n;
    }
};
