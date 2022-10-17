// 1832. Check if the Sentence Is Pangram

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int alpha[26] = {0};
        for (auto i : sentence) {
            alpha[i-'a'] = 1;
        }
        for(auto i : alpha) {
            if(i == 0) {
                return false;
            }
        }
        return true;
    }
};
