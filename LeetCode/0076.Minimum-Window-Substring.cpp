// 76. Minimum Window Substring

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mps;
        unordered_map<char,int> mpt;
        
        for(auto i : t) {
            mpt[i]++;
        }
        
        int i = 0;
        int j = 0;
        int n = s.length();
        int cnt = 0;
        int dcnt = t.length();
        string ans = "";
        
        while(true) {
            bool f1 = false;
            bool f2 = false;
            
            while(i<n && cnt<dcnt) {
                if(mpt.find(s[i]) != mpt.end()) {
                    mps[s[i]]++;
                    if(mps[s[i]] <= mpt[s[i]]) {
                        cnt++;
                    }
                }
                f1 = true;
                i++;
            }
            
            while(j<i && cnt == dcnt) {
                string temp = s.substr(j,i-j);
                if(ans.length() == 0 || temp.length()<ans.length()) {
                    ans = temp;
                }
                if(mpt.find(s[j]) != mpt.end()) {
                    if(mps[s[j]] == 1) {
                        mps.erase(s[j]);
                    }
                    else {
                        mps[s[j]]--;
                    }
                    if(mps[s[j]] < mpt[s[j]]) {
                        cnt--;
                    }
                }
                f2 = true;
                j++;
            }
            
            if(f1 == false && f2 == false) {
                break;
            }
        }
        return ans;
    }
};
