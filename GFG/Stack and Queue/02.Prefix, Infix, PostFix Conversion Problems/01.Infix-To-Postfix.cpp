// Infix To Postfix

#include <bits/stdc++.h>

int precedence(char c) {
  	if(c == '^') {
  		  return 3;
  	}
  	else if(c == '*' || c == '/') {
  		  return 2;
  	}
  	else if(c == '+' || c == '-') {
  		  return 1;
  	}
  	return -1;
}

string infixToPostfix(string exp){
  	// Write your code here
  
  	stack<char> st;
  	string ans = "";
  
  	for(auto i : exp) {
    		if((i>='0' && i<='9') || (i>='a' && i<='z') || (i>='A' && i<='Z')) {
    			  ans += i;
    		}
    		else if(i == '(') {
    			  st.push(i);
    		}
    		else if(i == ')') {
      			while(!st.empty() && st.top()!='(') {
        				ans += st.top();
        				st.pop();
      			}
      			st.pop();
    		}
    		else {
      			while(!st.empty() && precedence(st.top()) >= precedence(i)) {
        				ans += st.top();
        				st.pop();
      			}
      			st.push(i);
      		}
  	}
  
  	while(!st.empty()) {
    		ans += st.top();
    		st.pop();
  	}
  
  	return ans;
}
// T : O(N)
// S : O(N)
