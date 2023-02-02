// 953. Verifying an Alien Dictionary

class Solution {
public:

    bool isSafe(string& s1, string& s2, vector<int>& abcd) {
        int ptr = 0;
        int n1 = s1.length();
        int n2 = s2.length();
        while(ptr<n1 && ptr<n2) {
            if(abcd[s1[ptr]-'a'] > abcd[s2[ptr]-'a']) {
                return false;
            }
            else if(abcd[s1[ptr]-'a'] < abcd[s2[ptr]-'a']) {
                return true;
            }
            ptr++;
        }
        if(ptr==n1 && ptr==n2) return true;
        else if(ptr == n2) return false;
        return true;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> abcd(26);
        for(int i=0; i<26; i++) {
            abcd[order[i]-'a'] = i;
        }
        
        for(int i=0; i<words.size()-1; i++) {
            if(!isSafe(words[i],words[i+1],abcd)) return false;
        }
        return true;
    }
};
