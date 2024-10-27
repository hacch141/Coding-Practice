// 1233. Remove Sub-Folders from the Filesystem

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string> st;
        for(auto s : folder) st.insert(s);

        vector<string> ans;
        for(auto s : folder) {
            string curr = s;
            bool f = true;
            while(curr != "" && f) {
                while(curr.back() != '/') curr.pop_back();
                curr.pop_back();
                if(st.count(curr)) f = false;
            }
            if(f) ans.push_back(s);
        }
        return ans;
    }
};
