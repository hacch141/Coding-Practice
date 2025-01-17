// 2683. Neighboring Bitwise XOR

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();

        vector<int> original(n, 0);
        for(int i = 0; i < n - 1; i++) {
            if(derived[i] == 0) {
                original[i + 1] = original[i];
            }
            else {
                original[i + 1] = 1 - original[i];
            }
        }
        if(derived[n - 1] == original[0] ^ original[n - 1]) return true;

        original[0] = 1;
        for(int i = 0; i < n - 1; i++) {
            if(derived[i] == 0) {
                original[i + 1] = original[i];
            }
            else {
                original[i + 1] = 1 - original[i];
            }
        }
        if(derived[n - 1] == original[0] ^ original[n - 1]) return true;

        return false;
    }
};
