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



#include <bits/stdc++.h>

class Node {
	public:
	char data;
	Node *left, *right;

	Node(char data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

bool isOperator(char c) {
	return (!isalpha(c) && !isdigit(c));
}

void helper(Node*& head, string& ans) {
	if(!head) return;
	ans += '(';
	helper(head->left,ans);
	ans.pop_back();
	ans += head->data;
	helper(head->right,ans);
	ans += ')';
}

string prefixToInfixConversion(string &s){
	// Write your code here.
	int n = s.length();
	stack<Node*> st;

	for(int i=n-1; i>=0; i--) {
		if(isOperator(s[i])) {
			Node* a = st.top();
			st.pop();
			Node* b = st.top();
			st.pop();

			Node* newNode = new Node(s[i]);
			newNode->left = a;
			newNode->right = b;

			st.push(newNode);
		}
		else {
			Node* a = new Node(s[i]);
			st.push(a);
		}
	}

	string ans;
	helper(st.top(),ans);
	ans.resize(ans.size()-1);

	return ans;
}
// T : O(N)
// S : O(N)
