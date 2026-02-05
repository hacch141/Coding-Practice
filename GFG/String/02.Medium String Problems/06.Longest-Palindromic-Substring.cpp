// Longest Palindromic Substring

class Solution {
    private String expand(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return s.substring(left + 1, right);
    }

    public String longestPalindrome(String s) {
        if (s.length() == 0) return "";
        String longest = "";
        for (int i = 0; i < s.length(); i++) {
            // Odd length palindrome
            String odd = expand(s, i, i);
            if (odd.length() > longest.length()) longest = odd;

            // Even length palindrome
            String even = expand(s, i, i + 1);
            if (even.length() > longest.length()) longest = even;
        }

        return longest;
    }
}

// ============================================================================

class Solution {
public:
    string get_pal(string s,int left,int right){
     int n = s.length();
     while(left>=0 && right<n){
         if(s[left]!=s[right]){
             break;
         }
         left--;
         right++;
     }
     return s.substr(left+1,right-left-1);
   }
    string longestPalindrome(string s) {
        int n=s.length();
        if(s.empty()) return 0;
        string longest;
        
        for(int i=0;i<n;i++){
            string odd=get_pal(s,i,i);
            if(odd.length()>longest.length())
                longest=odd;
        }
        
        for(int i=0;i<n;i++){
            string even=get_pal(s,i,i+1);
            if(even.length()>longest.length())
                longest=even;
        }
        return longest;
    }
};
// T : O(N*K) k = length of palindromic substring
// S : O(N)
