// 1678. Goal Parser Interpretation

class Solution {
public:
    string interpret(string command) {
        string ans = "";
        for(int i=0; i<command.length(); i++) {
            if(command[i]=='(' && command[i+1]==')') {
                ans += 'o';
                i++;
            }
        else if(command[i]=='(' && command[i+1]=='a' && command[i+2]=='l' && command[i+3]==')') {
                ans += "al";
                i += 3;
            }
            else {
                ans += command[i];
            }
        }
        return ans;
    }
};
