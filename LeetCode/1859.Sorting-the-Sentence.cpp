// 1859. Sorting the Sentence

class Solution {
public:
    string sortSentence(string s) {
        vector<string> ansvec(10, "");
        string ans = "";
        string word = "";
        for(int i=0; i<s.length(); i++) {
            if(s[i]>='0' && s[i]<='9') {
                ansvec[s[i]-'0'] = word;
                i++;
                word = "";
            }
            else {
                word += s[i];
            }
        }
        for(int i=0; i<ansvec.size(); i++) {
            if(ansvec[i]!="") {
                ans += ansvec[i]+' ';
            }
        }
        ans.resize(ans.size()-1);
        return ans;
    }
};
