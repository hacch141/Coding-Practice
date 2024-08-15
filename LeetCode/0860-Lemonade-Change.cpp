// 860. Lemonade Change
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5 = 0, c10 = 0, c20 = 0;
        for(auto i : bills) {
            if(i == 5) {
                c5++;
            }
            else if(i == 10) {
                if(c5 > 0) {
                    c5--;
                }
                else {
                    return false;
                }
                c10++;
            }
            else {
                if(c10 > 0 && c5 > 0) {
                    c10--;
                    c5--;
                    c20++;
                }
                else if(c5 > 2) {
                    c5 -= 3;
                    c20++;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
