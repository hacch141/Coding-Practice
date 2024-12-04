// 2825. Make String a Subsequence Using Cyclic Increments

class Solution {
public:
    char get_next(char& ch) {
        return (((ch - 'a') + 1) % 26) + 'a';
    }

    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size(), ptr = 0;
        for(int i = 0; i < n1; i++) {
            if(str1[i] == str2[ptr] || get_next(str1[i]) == str2[ptr]) ptr++;
            if(ptr == n2) break;
        }
        return ptr == n2;
    }
};
