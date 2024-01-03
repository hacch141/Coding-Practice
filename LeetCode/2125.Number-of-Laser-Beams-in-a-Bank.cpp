// 2125. Number of Laser Beams in a Bank

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev = 0, curr = 0;
        for(int i=0; i<bank.size(); i++) {
            for(auto i : bank[i]) {
                if(i == '1') curr++;
            }
            if(curr != 0) {
                ans += (prev * curr);
                prev = curr;
                curr = 0;
            }
        }

        return ans;
    }
};
