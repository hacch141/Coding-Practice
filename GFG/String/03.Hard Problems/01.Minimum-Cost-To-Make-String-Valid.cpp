// Minimum Cost To Make String Valid

#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  // Write your code here

  if(str.length()%2) return -1;

  stack<char> st;
  for(auto i : str) {
    if(i == '{') {
      st.push('{');
    }
    else {
      if (!st.empty() && st.top() == '{') {
        st.pop();
      }
      else {
        st.push('}');
      }
    }
  }

  int p = 0, q = 0;

	while (!st.empty()) {
		if (st.top() == '{') {
			p++;
		}
		else {
			q++;
		}
		st.pop();
	}

  // stack }}{{  => ans : 2
  // stack }}}{{{ => ans : 4
  return ((p+1)/2) + ((q+1)/2);
}

// T : O(N)
// S : O(N)
