// 1945. Sum of Digits of String After Convert

class Solution {
public:
    string getNum(string s) {
        string num = "";
        for(auto ch : s) {
            num += to_string((ch - 'a') + 1);
        }
        return num;
    }

    void transform(string& s) {
        int sum = 0;
        for(auto ch : s) {
            sum += (ch - '0');
        }
        s = to_string(sum);
    }

    int getLucky(string s, int k) {
        string num = getNum(s);
        while(k--) {
            transform(num);
        }
        return stoi(num);
    }
};
