// 2337. Move Pieces to Obtain a String

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size(), p = 0, cl = 0, cr = 0;
        for(auto ch : start) cl -= ch == 'L', cr -= ch == 'R';
        for(auto ch : target) cl += ch == 'L', cr += ch == 'R';
        for(int i = 0; i < n; i++) {
            if(target[i] == 'L') {
                p = max(p, i);
                while(p < n && start[p] == '_') p++;
                if(p < n && start[p] == 'L') {
                    swap(start[i], start[p]);
                    p++;
                }
                else return false;
            }
        }
        p = n - 1;
        for(int i = n - 1; i >= 0; i--) {
            if(target[i] == 'R') {
                p = min(p, i);
                while(p >= 0 && start[p] == '_') p--;
                if(p >= 0 && start[p] == 'R') {
                    swap(start[i], start[p]);
                    p--;
                }
                else return false;
            }
        }
        return cl == 0 && cr == 0;
    }
};
