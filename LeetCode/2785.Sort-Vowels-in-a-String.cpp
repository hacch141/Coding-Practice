// 2785. Sort Vowels in a String

class Solution {
public:

    string sortVowels(string s) {
        set<char> st = {'a','e','i','o','u','A','E','I','O','U'};
        vector<int> freq(128,0);

        int n = s.length();
        for(int i=0; i<n; i++) {
            if(st.find(s[i]) != st.end()) {
                freq[s[i]]++;
            }
        }

        int ptr=0;
        for(int i=0; i<n; i++) {
            if(st.find(s[i]) != st.end()) {
                while(freq[ptr] == 0) ptr++;
                s[i] = (char)ptr;
                freq[ptr]--;
            }
        }

        return s;
    }
};

// ========================================================================================

class Solution {
public:

    string sortVowels(string s) {
        set<char> st = {'a','e','i','o','u','A','E','I','O','U'};
        string str = "";
        int n = s.length();
        
        for(int i=0; i<n; i++) {
            if(st.find(s[i]) != st.end()) {
                str += s[i];
            }
        }

        sort(str.begin(),str.end());

        int ptr=0;
        for(int i=0; i<n; i++) {
            if(st.find(s[i]) != st.end()) {
                s[i] = str[ptr++];
            }
        }

        return s;
    }
};
