// 3403. Find the Lexicographically Largest String From the Box I

class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        int n = word.length();

        int i = 0, j = 1;
        while(j < n) {
            int k = 0;
            while(j + k < n && word[i + k] == word[j + k]) {
                k++;
            }

            if(j + k < n && word[i + k] < word[j + k]) {
                int tmp = i;
                i = j;
                j = max(j + 1, tmp + k + 1);
            }
            else {
                j = j + k + 1;
            }
        }

        int long_pos = min(n - i, n - (numFriends - 1));
        return word.substr(i, long_pos);
    }
};
