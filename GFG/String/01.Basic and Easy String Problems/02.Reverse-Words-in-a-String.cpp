// Reverse Words in a String

class Solution {
    public String reverseWords(String s) {
        String[] ss = s.trim().split("\\s+");
        int n = ss.length;

        for (int i = 0; i < n / 2; i++) {
            String tmp = ss[i];
            ss[i] = ss[n - 1 - i];
            ss[n - 1 - i] = tmp;
        }

        return String.join(" ", ss);
    }
}

// =======================================================================

#include <bits/stdc++.h>

string reverseString(string &str){
  	// Write your code here.
  	string curr = "";
  	string ans = "";
  	for(auto i : str) {
    		if(i != ' ') {
    			  curr += i;
    		}
    		else {
      			if(curr.length() > 0) {
        				if(ans.length() > 0) {
        					  ans = curr + " " + ans;
        				}
        				else {
        					  ans = curr;
        				}
      			}
      			curr = "";
    		}
  	}
  
  	if(curr.length() > 0) {
  		  if(ans.length() > 0) {
  			    ans = curr + " " + ans;
  		  }
  		  else {
  			    ans = curr;
  		  }  		
  	}
  
  	return ans;
}

// T : O(N)
// S : O(N)


/*
    Time Complexity  = O(N * 2)
    Space Complexity = O(N)
   
    Where N is the length of the string.
*/

string reverseString(string &str)
{
    int n = str.length();
  	string ans;
  	int i = 0;
  
  	while (i < n) 
  	{
  		  int j = i;
    		// Skip multiple spaces.
    		while (j < n && str[j] == ' ') {
    			  j++;
    		}
  		  string currentWord;
  		  // Get the current word.
  		  while (j < n && str[j] != ' ') {
  			    currentWord.push_back(str[j]);
  			    j++;
  		  }
    		// Add current word in the ans with a space.
    		if (currentWord.length() != 0) {
    			  ans.insert(0, currentWord + " ");
    		}
    		i = j + 1;
    }
  
  	if (ans.length() == 0) {
    		return ans;
  	}
  	// Remove the last space.
  	return ans.substr(0, ans.length() - 1);
}
