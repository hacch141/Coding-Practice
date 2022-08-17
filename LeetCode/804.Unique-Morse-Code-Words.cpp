// 804. Unique Morse Code Words

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> arr = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> st;
        string temp = "";
        for(auto s : words) {
            temp = "";
            for(int j=0; j<s.length(); j++) {
                temp += arr[s[j]-'a'];
            }
            st.insert(temp);
        }
        return st.size();
    }
};
