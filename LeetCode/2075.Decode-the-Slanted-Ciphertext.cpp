// 2075. Decode the Slanted Ciphertext

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(rows == 1 || encodedText.length()==0) return encodedText;
        int n = encodedText.size();
        int cols = encodedText.length()/rows;

        string ans = "";
        for(int i=0; i<cols; i++) {
            int r=0, c=i;
            while(r < rows && c < cols) {
                ans += encodedText[r*cols + c];
                r++;
                c++;
            }
        }

        while(ans.length() > 0 && ans.back() == ' ') ans.pop_back();

        return ans;
    }
};
