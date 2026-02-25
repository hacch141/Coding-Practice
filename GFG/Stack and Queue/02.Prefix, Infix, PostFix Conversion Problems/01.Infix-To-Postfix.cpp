// Infix To Postfix

class Solution {
    public static String infixToPostfix(String exp) {

        StringBuilder result = new StringBuilder();
        Stack<Character> stack = new Stack<>();

        for (char ch : exp.toCharArray()) {

            // 1. If operand → add to result
            if (Character.isLetterOrDigit(ch)) {
                result.append(ch);
            }

            // 2. If '(' → push
            else if (ch == '(') {
                stack.push(ch);
            }

            // 3. If ')' → pop until '('
            else if (ch == ')') {
                while (!stack.isEmpty() && stack.peek() != '(') {
                    result.append(stack.pop());
                }
                stack.pop(); // remove '('
            }

            // 4. If operator
            else {
                while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
                    result.append(stack.pop());
                }
                stack.push(ch);
            }
        }

        // pop remaining operators
        while (!stack.isEmpty()) {
            result.append(stack.pop());
        }

        return result.toString();
    }

    public static int precedence(char op) {

        switch (op) {
            case '+':
            case '-':
                return 1;

            case '*':
            case '/':
                return 2;

            case '^':
                return 3;
        }

        return -1;
    }
}

// ==========================================================================

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
