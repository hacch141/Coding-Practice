// 648. Replace Words

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> st;
        for(auto s : dictionary) st.insert(s);
        string ans = "", cur = "";
        int n = sentence.length();
        for(int i = 0; i < n; i++) {
            if(sentence[i] != ' ') cur += sentence[i];
            if(st.count(cur) || sentence[i] == ' ') {
                ans += cur + " ";
                cur = "";
                while(i < n && sentence[i] != ' ') i++;
            }
        }
        if(cur.length() > 0) ans += cur;
        if(ans.back() == ' ') ans.pop_back();
        return ans;
    }
};
