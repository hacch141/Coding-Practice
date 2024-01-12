// 1704. Determine if String Halves Are Alike

class Solution {
public:
    bool halvesAreAlike(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        int cnt1 = 0, cnt2 = 0, n = s.length();
        for(int i=0; i<n/2 ; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') cnt1++;
            if(s[i+(n/2)] == 'a' || s[i+(n/2)] == 'e' || s[i+(n/2)] == 'i' || s[i+(n/2)] == 'o' || s[i+(n/2)] == 'u') cnt2++;
        }
        return cnt1 == cnt2;
    }
};


class Solution {
public:
    bool halvesAreAlike(string s) {
        set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int cnt1 = 0, cnt2 = 0, n = s.length();
        for(int i=0; i<n/2 ; i++) {
            if(st.count(s[i])) cnt1++;
            if(st.count(s[i+(n/2)])) cnt2++;
        }
        return cnt1 == cnt2;
    }
};
