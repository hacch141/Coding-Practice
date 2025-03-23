// 752. Open the Lock

class Solution {
public:
    char get_next(char ch) {
        if(ch == '9') return '0';
        ch++;
        return ch;
    }

    char get_prev(char ch) {
        if(ch == '0') return '9';
        ch--;
        return ch;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st;
        for(auto &s : deadends) st.insert(s);

        if (st.count("0000")) return -1; 

        queue<string> q;
        q.push("0000");

        unordered_set<string> vis;
        vis.insert("0000");

        int cnt = 0;

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                string u = q.front();
                q.pop();

                if(u == target) return cnt;

                for(int i = 0; i < 4; i++) {
                    char ch = u[i];

                    char nxt = get_next(ch);
                    u[i] = nxt;
                    if(!st.count(u) && !vis.count(u)) {
                        vis.insert(u);
                        q.push(u);
                    }

                    char prv = get_prev(ch);
                    u[i] = prv;
                    if(!st.count(u) && !vis.count(u)) {
                        vis.insert(u);
                        q.push(u);
                    }
                    
                    u[i] = ch;
                }
            }
            cnt++;
        }

        return -1;
    }
};
