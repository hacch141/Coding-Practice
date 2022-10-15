// 290. Word Pattern

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,int> mpchar;
        unordered_map<string,int> mpstr;
        unordered_map<char,string> cs;
        
        for(auto i : pattern) {
            mpchar[i]++;
        }
        
        string str = "";
        for(int i=0; i<s.length(); i++) {
            if(s[i] != ' ') {
                str += s[i];
            }
            else {
                mpstr[str]++;
                str = "";
            }
        }
        mpstr[str]++;
        
        if(mpchar.size() != mpstr.size()) {
            return false;
        }
        
        int j=0;
        for(int i=0; i<pattern.length(); i++) {
            str = "";
            while(s[j] != ' ' && j<s.length()) {
                str += s[j];
                j++;
            }
            j++;
            
            if(cs.find(pattern[i]) != cs.end()) {
                if(cs[pattern[i]] != str) {
                    return false;
                }
            }
            else {
                cs[pattern[i]] = str;
            }
            
            if(mpstr[str] != mpchar[pattern[i]]) {
                return false;
            }
        }
        
        if(cs.size() != mpchar.size()) {
            return false;
        }
        return true;
    }
};
