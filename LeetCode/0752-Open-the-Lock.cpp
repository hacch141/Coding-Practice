// 752. Open the Lock

class Solution {
public:

    char rotateLeft(char ch) {
        return ch == '0' ? '9' : ch - 1;
    }

    char rotateRight(char ch) {
        return ch == '9' ? '0' : ch + 1;
    }

    vector<string> genAll(string s) {
        vector<string> v;
        for(int i = 0; i < 4; i++) {
            string temp = s;

            temp[i] = rotateLeft(s[i]);
            v.push_back(temp);

            temp[i] = rotateRight(s[i]);
            v.push_back(temp);
        }
        return v;
    }

    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        q.push("0000");
        map<string,bool> vis;
        for(auto s : deadends) {
            vis[s] = true;
        }

        int lvl = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                string curr = q.front();
                q.pop();

                if(curr == target) return lvl;
                if(vis[curr]) continue;
                vis[curr] = true;

                vector<string> nxt = genAll(curr);
                for(auto s : nxt) {
                    if(!vis[s]) q.push(s);
                }
            }
            lvl++;
        }
        return -1;
    }
};
