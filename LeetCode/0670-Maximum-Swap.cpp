// 670. Maximum Swap

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length(), mx = -1, lst = -1;
        for(int i = n - 1; i >= 0; i--) {
            int cur = (s[i] - '0');
            if(mx > cur) {
                lst = i;
            }
            mx = max(mx, s[i] - '0');
        }
        int lst2 = -1, mx2 = -1;
        for(int i = n - 1; i > lst; i--) {
            int cur = (s[i] - '0');
            if(cur > mx2) {
                lst2 = i;
            }
            mx2 = max(mx2, s[i] - '0');
        }
        if(lst != -1 && lst2 != -1 && s[lst] < s[lst2]) swap(s[lst], s[lst2]);
        return stoi(s);
    }
};
