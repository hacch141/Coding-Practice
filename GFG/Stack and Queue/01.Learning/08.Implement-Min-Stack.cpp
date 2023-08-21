// Implement Min Stack

#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	public:
		vector<int> v;
		vector<int> miniv;
		int mini;
		// Constructor
		minStack() 
		{ 
  			// Write your code here.
  			mini = INT_MAX;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
  			// Write your code here.
  			v.push_back(num);
  			if(miniv.size() == 0) {
  			  	miniv.push_back(num);
  			}
  			else {
    				mini = min(miniv.back(),num);
    				miniv.push_back(mini);
  			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
  			// Write your code here.
  			if(v.size() == 0) return -1;
  			int a = v.back();
  			v.pop_back();
  			miniv.pop_back();
  			return a;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
  			// Write your code here.
  			if(v.size() == 0) return -1;
  			return v.back();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
  			// Write your code here.
  			if(miniv.size() == 0) return -1;
  			return miniv.back();
		}
};
