// 1598. Crawler Log Folder

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for(auto s : logs) {
            s.pop_back();
            if(s == ".") {
                continue;
            }
            else if(s == "..") {
                cnt = max(0, cnt - 1);
            }
            else {
                cnt++;
            }
        }
        return cnt;
    }
};
