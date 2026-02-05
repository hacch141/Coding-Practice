// Reverse Every Word in A String

class Solution {
    public String reverseWords(String s) {
        String[] ss = s.trim().split("\\s+");
        Collections.reverse(Arrays.asList(ss));
        return String.join(" ", ss);
    }
}

// ====================================================================

string revWords(string str) {
    // Write your code here.
    string ans = "";
    string temp = "";
    for(auto i : str) {
        if(i != ' ') {
            temp += i;
        }
        else {
            if(temp.size() > 0) {
                if(ans.size() == 0) {
                    ans = temp;
                }
                else {
                    ans = temp + " " + ans;
                }
                temp = "";
            }
        }
    }
    if(temp.size() > 0) {
        if(ans.size() == 0) {
            ans = temp;
        }
        else {
            ans = temp + " " + ans;
        }
        temp = "";
    }

    return ans;
}
// T : O(N)
// S : O(N)


/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where 'N' is the length of the string 'str'.
*/

string revWords(string str) {

    // If the input string is empty, return the same string.
    if (str.length() == 0) {
        return str;
    }

    // Initialize an empty string to store the reversed words.
    string ans = "";

    // If the input string has only one character, which is a space, return an empty string.
    if (str.length() == 1 && str[0] == ' ') {
        return ans;
    }

    // Initialize the index 'i' to the last character of the input string.
    int i = str.length() - 1;

    // Loop through the input string from the end to the beginning.
    while (i >= 0) {

        // Skip multiple spaces by decrementing the index 'i'
        if (str[i] == ' ') {
            i--;
        } 
        else {

            // If there is already a word in the 'ans', add a space before the next word.
            if (ans.length() > 0) {
                ans += " ";
            }

            // Initialize index 'j' to the current value of 'i'.
            int j = i;

            // Loop for extracting the current word by moving 'j' to the beginning of the word.
            while (j >= 0 && str[j] != ' ') {
                j--;
            }

            // Add the current word to the 'ans' by extracting the substring from 'j+1' to 'i'.
            ans += str.substr(j + 1, i - j);

            // Update 'i' to the value of 'j' to move to the next word in the next iteration.
            i = j;
        }
    }

    // Return the final reversed string containing words separated by a single space.
    return ans;
}
