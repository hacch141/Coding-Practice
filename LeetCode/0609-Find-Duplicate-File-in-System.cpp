// 609. Find Duplicate File in System

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> mp;
        for(auto path : paths) {
            stringstream ss(path);
            string dir, token;
            getline(ss, dir, ' ');
            while(getline(ss, token, ' ')) {
                int l = token.find('(');
                int r = token.find(')');
                string file = token.substr(0, l);
                string content = token.substr(l + 1, r - l + 1);
                mp[content].push_back(dir + "/" + file);
            }
        }

        vector<vector<string>> ans;
        for(auto it : mp) {
            if(it.second.size() > 1) {
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};
