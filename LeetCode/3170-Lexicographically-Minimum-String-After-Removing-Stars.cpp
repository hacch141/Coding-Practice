// 3170. Lexicographically Minimum String After Removing Stars

class Solution {
public:
    string clearStars(string s) {
        int n = s.length();

        // Lambda comparator: smaller char first, if equal then higher index first
        auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
            if (a.first == b.first) return a.second < b.second; // latest index first
            return a.first > b.first; // smallest character on top
        };

        vector<bool> vis(n, false);
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq;

        for(int i = 0; i < n; i++) {
            if(s[i] == '*') {
                vis[i] = true;
                auto p = pq.top();
                vis[p.second] = true;
                pq.pop();
            }
            else {
                pq.push({s[i], i});
            }
        }

        string ans = "";
        for(int i = 0; i < n; i++) {
            if(!vis[i]) ans += s[i];
        }

        return ans;
    }
};

// 
class Solution {
public:
    string clearStars(string s) {
        int n = s.length();

        vector<vector<int>> v(26);
        vector<bool> rem(n, false);

        for(int i = 0; i < n; i++) {
            if(s[i] != '*') {
                v[s[i] - 'a'].push_back(i);
            }
            else {
                rem[i] = true;
                for(int j = 0; j < 26; j++) {
                    if(!v[j].empty()) {
                        rem[v[j].back()] = true;
                        v[j].pop_back();
                        break;
                    }
                }
            }
        }

        string ans = "";
        for(int i = 0; i < n; i++) {
            if(!rem[i]) ans += s[i];
        }

        return ans;
    }
};
