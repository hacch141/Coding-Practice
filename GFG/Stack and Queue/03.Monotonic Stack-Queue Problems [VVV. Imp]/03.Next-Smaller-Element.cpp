// Next Smaller Element

void printNSE(int arr[], int n)
{
    stack<pair<int, int> > s;
    vector<int> ans(n);
 
    // iterate for rest of the elements
    for (int i = 0; i < n; i++) {
        int next = arr[i];
 
        // if stack is empty then this element can't be NSE
        // for any other element, so just push it to stack
        // so that we can find NSE for it, and continue
        if (s.empty()) {
            s.push({ next, i });
            continue;
        }
 
        // while stack is not empty and the top element is
        // greater than next
        //  a) NSE for top is next, use top's index to
        //    maintain original order
        //  b) pop the top element from stack
 
        while (!s.empty() && s.top().first > next) {
            ans[s.top().second] = next;
            s.pop();
        }
 
        // push next to stack so that we can find NSE for it
 
        s.push({ next, i });
    }
 
    // After iterating over the loop, the remaining elements
    // in stack do not have any NSE, so set -1 for them
 
    while (!s.empty()) {
        ans[s.top().second] = -1;
        s.pop();
    }
 
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ---> " << ans[i] << endl;
    }
}


void immediateSmaller(vector<int>& a)
{
  	// Write your code here.
  	int n = a.size();
  
  	for(int i=0; i<n-1; i++) {
    		if(a[i+1] < a[i]) {
    			  a[i] = a[i+1];
    		}
    		else {
    			  a[i] = -1;
    		}
  	}
  	a[n-1] = -1;
}
// T : O(N)
// S : O(N)


/*
    Time Complexity: O(n)
    Space complexity: O(n)

    Where 'n' is the number of elements in the array.
*/

#include<stack>

void immediateSmaller(vector<int>& a)
{
    int n = a.size();

    // Use a stack to store previous element
    stack<int> s;
    s.push(a[0]);

    for (int i = 1; i < n; i++)
    {
        // If the top is greater than the current element then copy the current element to previous
        if (s.top() > a[i])
        {
            a[i - 1] = a[i];
        }
        else
        {
            // Else set it to -1;
            a[i - 1] = -1;
        }

        // Push the current element to top for next Iteration
        s.push(a[i]);
    }

    // Finally for the last element put it as -1
    a[n - 1] = -1;
}
