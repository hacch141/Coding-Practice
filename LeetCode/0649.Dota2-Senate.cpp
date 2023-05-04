// 649. Dota2 Senate

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q1,q2,q3,q4;
        for(int i=0; i<senate.size(); i++) {
            if(senate[i]=='R') q1.push(i);
            else q2.push(i);
        }
        if(q1.empty() && q3.empty()) return "Dire";
        if(q2.empty() && q4.empty()) return "Radiant";

        while(1) {
            if(!q1.empty() && !q2.empty()) {
                int r = q1.front();
                int d = q2.front();
                cout << "r : " << r << endl;
                cout << "d : " << d << endl;
                q1.pop();q2.pop();
                if(r<d) {
                    q3.push(r);
                }
                else {
                    q4.push(d);
                }
            }
            else if(q1.empty() && !q2.empty()) {
                q3.pop();
                int d = q2.front();
                q2.pop();
                q4.push(d);
            }
            else if(q2.empty() && !q1.empty()){
                q4.pop();
                int r = q1.front();
                q1.pop();
                q3.push(r);
            }
            else {
                q1 = q3;
                q2 = q4;
                queue<int> empty1;
                queue<int> empty2;
                swap(q3,empty1);
                swap(q4,empty2);
            }

            if(q1.empty() && q3.empty()) return "Dire";
            if(q2.empty() && q4.empty()) return "Radiant";
        }
        return "";
    }
};
