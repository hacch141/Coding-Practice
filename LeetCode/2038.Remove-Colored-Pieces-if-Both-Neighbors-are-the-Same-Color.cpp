// 2038. Remove Colored Pieces if Both Neighbors are the Same Color

class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length();
        int cntA=0, cntB=0, cnt=1;
        char ele = colors[0];

        for(int i=1; i<n; i++) {
            if(colors[i] == ele) {
                cnt++;
                if(cnt >= 3) {
                    ele == 'A' ? cntA++ : cntB++;
                }
            }
            else {
                ele = colors[i];
                cnt = 1;
            }
        }

        return cntA > cntB;
    }
};
