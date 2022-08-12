// 151. Reverse Words in a String

class Solution {
public:
    
    string reverseWords(string s) {
        vector<string> temp;
        string str = "";
        
        for(int i=0; i<s.length(); i++) {
            if(s[i]==' ' && str.length()>0) {
                temp.push_back(str);
                str = "";
            }
            else if(s[i] != ' ') {
                str += s[i];
            }
        }
        if(s[s.length()-1] != ' ') {
            temp.push_back(str);   
        }
        reverse(temp.begin(),temp.end());
        s = "";
        for(auto st : temp) {
            s += st;
            s += " ";
        }
        s.resize(s.length()-1);
        return s;
    }
};
