// Prefix to Infix Conversion

#include <bits/stdc++.h>

bool isOperator(char c) {
	  return (!isalpha(c) && !isdigit(c));
}

string prefixToInfixConversion(string &s){
  	// Write your code here.
  	int n = s.length();
  	stack<string> st;
  
  	for(int i=n-1; i>=0; i--) {
    		if(isOperator(s[i])) {
      			string a = st.top();
      			st.pop();
      			string b = st.top();
      			st.pop();
      			st.push('(' + a + s[i] + b + ')');
    		}
    		else {
    		  	st.push(string(1,s[i]));
    		}
  	}
  
  	return st.top();
}

// T : O(N)
// S : O(N)
